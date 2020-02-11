/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:10:35 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 15:10:07 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_error(t_listdir *not_found)
{
	int		i;

	i = -1;
	ft_merge_sort(not_found, 0, not_found->book.cursor);
	while (++i <= not_found->book.cursor)
	{
		ft_dprintf(2, "ft_ls: %s: ",
			not_found->book.list[i]);
		perror("");
	}
	free_array_list(&(not_found->book));
}

static void	no_arg_case(t_listdir *listdir)
{
	t_datum			*element;

	if (!(element = (t_datum *)malloc(sizeof(t_datum))))
		exit(1);
	lstat(".", &(element->stat));
	element->filename = (char *)malloc(2);
	if (!(ft_memcpy(element->filename, ".", 2)))
		exit(1);
	append(&(listdir->book), element);
}

static void	ft_valid(t_listdir *listdir, t_datum *element, char *str)
{
	element->filename = ft_strdup(str);
	element->path = ft_strdup(str);
	append(&(listdir->book), element);
}

void		ft_get_list(char **argv, int argc, int mark, t_listdir *listdir)
{
	int				i;
	t_datum			*element;
	t_listdir		not_found_list;

	i = -1;
	if (mark < 1 || mark == argc)
	{
		no_arg_case(listdir);
		return ;
	}
	init_array_list(&(not_found_list.book));
	not_found_list.options = NULL;
	while (++i < argc - mark)
	{
		if (!(element = (t_datum *)malloc(sizeof(t_datum))))
			continue ;
		if (lstat(argv[i], &(element->stat)) == -1)
		{
			append(&(not_found_list.book), ft_strdup(argv[i]));
			free(element);
		}
		else
			ft_valid(listdir, element, argv[i]);
	}
	ft_error(&not_found_list);
}
