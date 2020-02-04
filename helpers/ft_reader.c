/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:19:51 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/04 20:11:14 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void			ft_router(t_listdir *listdir, t_datum *datum, int i)
{
	if ((LIST | FLAG_G) & *listdir->options)
		ft_print_flag_list(listdir, listdir->max_lenght, i);
	else
		printf("%s\n", datum->filename);
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
			if (!(*(p_listdir->options) & ALL) && (dirent->d_name)[0] == '.')
				continue ;
			element = (t_datum *)malloc(sizeof(t_datum));
			full_path = ft_join_path(path, dirent->d_name);
			if (lstat(full_path, &(element->stat)) == -1)
			{
				free(element);
				free(full_path);
				continue ;
			}
			free(full_path);
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

static int			ft_print_listdir(t_listdir *listdir, int bulb)
{
	int			i;
	int			printed;
	t_datum		*datum;

	i = -1;
	printed = 0;
	if ((LIST | FLAG_G) & *listdir->options)
		listdir->max_lenght = find_max_lenght(listdir);
	while (++i <= listdir->book.cursor)
	{
		datum = (t_datum *)(listdir->book.list[i]);
		if (bulb == TRUE)
		{
			// (S_ISLNK(datum->stat.st_mode) && LIST & *listdir->options &&
			// 	datum->filename[ft_strlen(datum->filename) - 1] == '/')
			if (!S_ISDIR(datum->stat.st_mode) || (*listdir->options & FLAG_D))
			{
				ft_router(listdir, datum, i);
				++printed;
			}
		}
		else
		{
			ft_router(listdir, datum, i);
			printed = 1;
		}
	}
	return (printed);
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
			if (S_ISDIR(datum->stat.st_mode))
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
