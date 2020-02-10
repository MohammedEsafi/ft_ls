/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhaoui <aalhaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:10:35 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/10 19:32:54 by aalhaoui         ###   ########.fr       */
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

	element = (t_datum *)malloc(sizeof(t_datum));
	lstat(".", &(element->stat));
	element->filename = (char *)malloc(2);
	ft_memcpy(element->filename, ".", 2);
	append(&(listdir->book), element);
}

void		ft_get_list(char **argv, int argc, int mark, t_listdir *listdir)
{
	int				i;
	t_datum			*element;
	t_listdir		not_found_list;

	i = -1;
	listdir->parent = NULL;
	if (mark < 1 || mark == argc)
	{
		no_arg_case(listdir);
		return ;
	}
	init_array_list(&(not_found_list.book));
	not_found_list.options = NULL;
	while (++i < argc - mark)
	{
		element = (t_datum *)malloc(sizeof(t_datum));
		if (lstat(argv[i], &(element->stat)) == -1)
		{
			append(&(not_found_list.book), ft_strdup(argv[i]));
			free(element);
		}
		else
		{
			element->filename = ft_strdup(argv[i]);
			element->path = ft_strdup(argv[i]);
			append(&(listdir->book), element);
		}
	}
	ft_error(&not_found_list);
}
