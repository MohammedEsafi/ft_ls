/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:10:35 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/02 10:01:21 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_not_found_list(t_listdir *not_found)
{
	int		i;

	i = -1;
	ft_merge_sort(not_found, 0, not_found->book.cursor);
	while (++i <= not_found->book.cursor)
	{
		ft_printf("ft_ls: %s: No such file or directory\n", not_found->book.list[i]);
	}
}

void		ft_get_list(char **argv, int argc, int mark, t_listdir *listdir)
{
	int				i;
	t_datum			*element;
	t_listdir		not_found_list;

	i = -1;
	if (mark < 1 || mark == argc)
		return ;
	init_array_list(&(not_found_list.book));
	not_found_list.options = NULL;
	listdir->parent = NULL;
	while (++i < argc - mark)
	{
		element = (t_datum *)malloc(sizeof(t_datum));
		if (lstat(argv[i], &(element->stat)) == -1)
		{
			append(&(not_found_list.book), argv[i]);
			free(element);
		}
		else
		{
			element->filename = argv[i];
			append(&(listdir->book), element);
		}
	}
	ft_not_found_list(&not_found_list);
}
