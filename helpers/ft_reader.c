/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:19:51 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/12 17:42:47 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void			ft_readdir(DIR *dir, t_listdir *listdir, int opt,
					char *path)
{
	struct dirent	*dirent;
	t_datum			*element;
	char			*full_path;

	while ((dirent = readdir(dir)) != NULL)
	{
		if (!(opt & (ALL | FLAG_F)) && (dirent->d_name)[0] == '.')
			continue ;
		if (!(element = (t_datum *)malloc(sizeof(t_datum))))
			break ;
		full_path = ft_join_path(path, dirent->d_name);
		if (lstat(full_path, &(element->stat)) == -1)
		{
			free(element);
			free(full_path);
			continue ;
		}
		element->path = full_path;
		if (!(element->filename = (char *)malloc(dirent->d_namlen + 1)))
			break ;
		ft_memcpy(element->filename, dirent->d_name, dirent->d_namlen + 1);
		append(&(listdir->book), element);
	}
}

static t_listdir	*new_listdir(char *path, char *filename,
						t_listdir *p_listdir, int bulb)
{
	t_listdir		*listdir;
	DIR				*dir;

	if (!(listdir = (t_listdir *)malloc(sizeof(t_listdir))))
		return (NULL);
	listdir->parent = path;
	listdir->max_lenght = NULL;
	listdir->options = p_listdir->options;
	if (!(bulb == TRUE && p_listdir->book.cursor == 0))
		ft_printf("%s:\n", path);
	init_array_list(&(listdir->book));
	if ((dir = opendir(path)))
		ft_readdir(dir, listdir, *(p_listdir->options), path);
	else
	{
		ft_dprintf(2, "ft_ls: %s: ", filename);
		perror("");
		free(listdir->parent);
		free(listdir->book.list);
		ft_memdel((void **)&listdir);
	}
	if (dir != NULL)
		closedir(dir);
	return (listdir);
}

static int			ft_checker(t_listdir *listdir, t_datum *datum, int bulb)
{
	return (
		(S_ISDIR(datum->stat.st_mode) ||
		(LIST & *listdir->options &&
		S_ISLNK(datum->stat.st_mode) &&
		datum->filename[ft_strlen(datum->filename) - 1] == '/' &&
		is_link(listdir->parent, datum->filename)) ||
		(S_ISLNK(datum->stat.st_mode) &&
		!(LIST & *listdir->options) && bulb)) &&
		((!ft_strequ(datum->filename, ".") && !ft_strequ(datum->filename, ".."))
		|| bulb));
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
	if ((bulb == TRUE || (*(listdir->options) & RECURSIVE)) &&
		!(*listdir->options & FLAG_D))
		while (++i <= listdir->book.cursor)
		{
			datum = (t_datum *)(listdir->book.list[i]);
			if (ft_checker(listdir, datum, bulb))
			{
				(printed != 0) && ft_printf("\n");
				ft_reader(new_listdir(ft_join_path(listdir->parent,
				datum->filename), bulb == TRUE ? "\0" : datum->filename,
				listdir, bulb), FALSE);
				printed = 1;
			}
		}
	free_list_dir(listdir);
}
