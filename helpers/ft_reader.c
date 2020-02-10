/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:19:51 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/10 14:17:23 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void			ft_router(t_listdir *listdir, t_datum *datum, int i,
					t_col *d)
{
	char	*color;
	char	*rest;

	rest = (*listdir->options & COLOR) ? "\033[0m" : "\0";
	if ((LIST | FLAG_G | FLAG_1 | FLAG_M) & *listdir->options)
		color = ft_get_color(datum, *listdir->options);
	if (FLAG_M & *listdir->options)
	{
		if (i != listdir->book.cursor)
			ft_printf("%s%s, %s", color, datum->filename, rest);
		else
			ft_printf("%s%s%s", color, datum->filename, rest);
	}
	else if ((LIST | FLAG_G) & *listdir->options)
		ft_print_flag_list(listdir, listdir->max_lenght, i, color);
	else if (FLAG_1 & *listdir->options)
		ft_printf("%s%s%s\n", color, datum->filename, rest);
	else
	{
		(d->index > listdir->book.cursor) && (d->index = ++d->last_index);
		color = ft_get_color(listdir->book.list[d->index], *listdir->options);
		d->tmp = ft_print_flag_non_list(listdir, d->index, d, color);
		d->index += d->max_row_col[1];
		if (d->x == (d->max_row_col[3]) * d->max_row_col[2])
		{
			if (d->tmp1 + 1 == d->max_row_col[4])
				d->max_row_col[3] -= 1;
			d->x = 0;
			if (d->tmp != -1)
			{
				d->tmp1++;
				d->y++;
			}
			else
				d->tmp1++;
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
		ft_dprintf(2 ,"ft_ls: %s: ", filename);
		perror("");
		free(listdir->parent);
		free(listdir->book.list);
		ft_strdel((char **)&listdir);
	}
	if (dir != NULL)
		closedir(dir);
	return (listdir);
}

static void			init_t_col(t_col *data, t_listdir *listdir)
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
	data.max_row_col = NULL;
	if (!((LIST | FLAG_G | FLAG_1 | FLAG_M) & *listdir->options))
		init_t_col(&data, listdir);
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
	if (data.max_row_col != NULL)
		free(data.max_row_col);
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
		path = ft_join_path(parent, filename);
	buff_link = (char *)ft_memalloc(sizeof(char) * 1024);
	len  = readlink(path, buff_link, 1024);
	free(path);
	lstat(buff_link, &stat);
	free(buff_link);
	if (len == -1)
		return (1);
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
	if (listdir == NULL)
		return ;
	if (!(FLAG_F & *listdir->options))
		ft_merge_sort(listdir, 0, listdir->book.cursor);
	printed = ft_print_listdir(listdir, bulb);
	if ((bulb == TRUE || (*(listdir->options) & RECURSIVE))
		&& !(*listdir->options & FLAG_D))
		while (++i <= listdir->book.cursor)
		{
			datum = (t_datum *)(listdir->book.list[i]);
			if ((S_ISDIR(datum->stat.st_mode) || (LIST & *listdir->options &&
				S_ISLNK(datum->stat.st_mode) &&
				datum->filename[ft_strlen(datum->filename) - 1] == '/' &&
				is_link(listdir->parent, datum->filename)))
				&& ((!ft_strequ(datum->filename, ".") &&
					!ft_strequ(datum->filename, "..")) || bulb))
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
