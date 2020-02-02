/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:13:56 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/02 10:27:45 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_join_path(char *parent, char *child)
{
	char	*full_path;
	int		p_len;
	int		c_len;

	p_len = ft_strlen(parent);
	c_len = ft_strlen(child);
	if (parent == NULL)
	{
		full_path = (char *)malloc(c_len + 1);
		ft_memcpy(full_path, child, c_len + 1);
	}
	else
	{
		full_path = (char *)malloc(p_len + c_len + 2);
		ft_memcpy(full_path, parent, p_len);
		ft_memcpy(full_path + p_len, "/", 3);
		ft_memcpy(full_path + p_len + 1, child, c_len + 1);
	}
	return (full_path);
}

t_listdir	*new_listdir(char *path, t_listdir *p_listdir, int bulb)
{
	t_listdir		*listdir;
	char			*full_path;
	t_datum			*element;
	struct dirent	*dirent;
	DIR				*dir;

	listdir = (t_listdir *)malloc(sizeof(t_listdir));
	listdir->parent = path;
	listdir->options = p_listdir->options;
	if (!(bulb == TRUE && p_listdir->book.cursor == 0))
		ft_printf("\n%s:\n", path);
	init_array_list(&(listdir->book));
	if ((dir = opendir(path)))
	{
		while ((dirent = readdir(dir)) != NULL)
		{
			if (!(*(p_listdir->options) & ALL) && (dirent->d_name)[0] == '.')
				continue ;
			full_path = ft_join_path(path, dirent->d_name);
			element = (t_datum *)malloc(sizeof(t_datum));
			lstat(full_path, &(element->stat));
			free(full_path);
			element->filename = (char *)malloc(dirent->d_namlen + 1);
			ft_memcpy(element->filename, dirent->d_name, dirent->d_namlen + 1);
			append(&(listdir->book), element);
		}
	}
	else
		perror("");
	closedir(dir);
	return (listdir);
}

void	ft_print_listdir(t_listdir *listdir, int bulb)
{
	int		i;
	t_datum	*datum;

	i = -1;
	while (++i <= listdir->book.cursor)
	{
		datum = (t_datum *)(listdir->book.list[i]);
		if (bulb == TRUE)
		{
			if (S_ISREG(datum->stat.st_mode))
				ft_printf("‣ %s\n", datum->filename);
		}
		else
		{
			ft_printf("‣ %s\n", datum->filename);
		}
	}
}

void	ft_reader(t_listdir *listdir, int bulb)
{
	int		i;
	t_datum	*datum;

	i = -1;
	ft_merge_sort(listdir, 0, listdir->book.cursor);
	ft_print_listdir(listdir, bulb);
	if (bulb == TRUE || *(listdir->options) & RECURSIVE)
		while (++i <= listdir->book.cursor)
		{
			datum = (t_datum *)(listdir->book.list[i]);
			if (S_ISDIR(datum->stat.st_mode))
				ft_reader(new_listdir(ft_join_path(listdir->parent, datum->filename), listdir, bulb), FALSE);
		}
}

int		main(int argc, char **argv)
{
	unsigned int	options;
	unsigned int	i;
	t_listdir		*listdir;

	listdir = (t_listdir *)malloc(sizeof(t_listdir));
	init_array_list(&(listdir->book));
	i = ft_options(&options, argv, argc);
	ft_get_list(&argv[i], argc, i, listdir);
	listdir->options = &options;
	ft_reader(listdir, TRUE);
	return (0);
}
