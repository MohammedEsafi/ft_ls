/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:19:51 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/06 16:15:20 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static char			*ft_get_color(t_datum *datum, int opt)
{
	if (opt & COLOR)
	{
		if (S_ISDIR(datum->stat.st_mode) && (datum->stat.st_mode & S_IWOTH)
			&& !(datum->stat.st_mode & S_ISVTX))
			return (ft_strndup("\033[30;43m", 8));
		if (S_ISDIR(datum->stat.st_mode) && (datum->stat.st_mode & S_IWOTH)
			&& (datum->stat.st_mode & S_ISVTX))
			return (ft_strndup("\033[30;42m", 8));
		else if (S_ISDIR(datum->stat.st_mode))
			return (ft_strndup("\033[34m", 5));
		else if (S_ISLNK(datum->stat.st_mode))
			return (ft_strndup("\033[35m", 5));
		else if (S_ISSOCK(datum->stat.st_mode))
			return (ft_strndup("\033[32m", 5));
		else if (S_ISFIFO(datum->stat.st_mode))
			return (ft_strndup("\033[33m", 5));
		else if (S_IXUSR & datum->stat.st_mode)
			return (ft_strndup("\033[31m", 5));
		else if (S_ISBLK(datum->stat.st_mode))
			return (ft_strndup("\033[34;46m", 8));
		else if (S_ISCHR(datum->stat.st_mode))
			return (ft_strndup("\033[34;43m", 8));
	}
	return (ft_strndup("\0", 1));
}

static void			ft_router(t_listdir *listdir, t_datum *datum, int i,
					t_col *d)
{
	char	*color;

	color = ft_get_color(datum, *listdir->options);
	if ((LIST | FLAG_G) & *listdir->options)
		ft_print_flag_list(listdir, listdir->max_lenght, i, color);
	else if (FLAG_1 & *listdir->options)
		ft_printf("%s%s%s\n", color, datum->filename, RESET);
	else
	{
		ft_printf("%s", color);
		(d->index > listdir->book.cursor) && (d->index = ++d->last_index);
		d->tmp = ft_print_flag_non_list(d->x, d->y, listdir, d->index);
		d->index += d->max_row_col[1];
		if (d->x == (d->max_row_col[3]) * d->max_row_col[2])
		{
			if (d->y + d->tmp1 == d->max_row_col[4])
				d->max_row_col[3] -= 1;
			d->x = 0;
			if (d->tmp != -1)
				(d->y)++;
			else
				(d->tmp1)++;
		}
		else
			d->x += d->max_row_col[2];
	}
	free(color);
}

static t_listdir	*new_listdir(char *path, char *filename,
						t_listdir *p_listdir, int bulb)
{
	t_listdir		*listdir;
	char			*full_path;
	t_datum			*element;
	struct dirent	*dirent;
	DIR				*dir;

	listdir = (t_listdir *)malloc(sizeof(t_listdir));
	listdir->parent = path;
	listdir->max_lenght = NULL;
	listdir->options = p_listdir->options;
	if (!(bulb == TRUE && p_listdir->book.cursor == 0))
		ft_printf("%s:\n", path);
	init_array_list(&(listdir->book));
	if ((dir = opendir(path)))
	{
		while ((dirent = readdir(dir)) != NULL)
		{
			if (!(*(p_listdir->options) & (ALL | FLAG_F)) && (dirent->d_name)[0] == '.')
				continue ;
			element = (t_datum *)malloc(sizeof(t_datum));
			full_path = ft_join_path(path, dirent->d_name);
			if (lstat(full_path, &(element->stat)) == -1)
			{
				free(element);
				free(full_path);
				continue ;
			}
			element->path = full_path;
			element->filename = (char *)malloc(dirent->d_namlen + 1);
			ft_memcpy(element->filename, dirent->d_name, dirent->d_namlen + 1);
			append(&(listdir->book), element);
		}
	}
	else
	{
		ft_printf("ft_ls: %s: ", filename);
		perror("");
	}
	if (dir != NULL)
		closedir(dir);
	return (listdir);
}

static void			int_t_col(t_col *data, t_listdir *listdir)
{
	data->x = 0;
	data->y = cursor_first_pos();
	data->index = 0;
	data->last_index = 0;
	data->max_row_col = ft_get_parameter(listdir);
	data->tmp = 0;
	data->tmp1 = 0;
}

static int			ft_print_listdir(t_listdir *listdir, int bulb)
{
	int			i;
	int			printed;
	t_datum		*datum;
	t_col		data;

	i = -1;
	printed = 0;
	int_t_col(&data, listdir);
	if ((LIST | FLAG_G) & *listdir->options)
		listdir->max_lenght = find_max_lenght(listdir, bulb);
	while (++i <= listdir->book.cursor)
	{
		datum = (t_datum *)(listdir->book.list[i]);
		if (bulb == TRUE)
		{
			if (!S_ISDIR(datum->stat.st_mode) || (*listdir->options & FLAG_D))
			{
				if (S_ISLNK(datum->stat.st_mode) && !(LIST & *listdir->options))
					continue ;
				ft_router(listdir, datum, i, &data);
				++printed;
			}
		}
		else
		{
			ft_router(listdir, datum, i, &data);
			printed = 1;
		}
	}
	if (!((LIST | FLAG_G | FLAG_1) & *listdir->options) && printed != 0)
		write(1, "\n", 1);
	return (printed);
}

int					is_link(char *parent, char *filename)
{
	char			*buff_link;
	char			*path;
	char			*tmp;
	struct stat		stat;
	size_t			len;

	len = ft_strlen(filename);
	if (filename[len - 1] == '/')
	{
		tmp = ft_strndup(filename, len - 1);
		path = ft_join_path(parent, tmp);
		free(tmp);
	}
	else
	{
		path = ft_join_path(parent, filename);
	}
	buff_link = (char *)ft_memalloc(sizeof(char) * 1024);
	if (readlink(path, buff_link, 1024) == -1)
		return (1);
	lstat(buff_link, &stat);
	if (S_ISLNK(stat.st_mode))
		return (0);
	return (1);
}

void				ft_reader(t_listdir *listdir, int bulb)
{
	int		i;
	t_datum	*datum;
	int		printed;

	i = -1;
	if (!(FLAG_F & *listdir->options))
		ft_merge_sort(listdir, 0, listdir->book.cursor);
	printed = ft_print_listdir(listdir, bulb);
	if ((bulb == TRUE || (*(listdir->options) & RECURSIVE))
		&& !(*listdir->options & FLAG_D))
		while (++i <= listdir->book.cursor)
		{
			datum = (t_datum *)(listdir->book.list[i]);
			if (S_ISDIR(datum->stat.st_mode) || (LIST & *listdir->options &&
				S_ISLNK(datum->stat.st_mode) &&
				datum->filename[ft_strlen(datum->filename) - 1] == '/' &&
				is_link(listdir->parent, datum->filename)) ||
				(!(LIST & *listdir->options) && S_ISLNK(datum->stat.st_mode)))
			{
				if (printed != 0)
					ft_printf("\n");
				ft_reader(new_listdir(ft_join_path(listdir->parent,
				datum->filename), bulb == TRUE ? "\0" : datum->filename,
				listdir, bulb), FALSE);
				printed = 1;
			}
		}
	free_list_dir(listdir);
}
