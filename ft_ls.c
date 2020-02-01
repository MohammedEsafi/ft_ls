/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:13:56 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/01 11:34:31 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// void	ft_reader(t_listdir *listdir, unsigned int options)
// {
// 	(void)options;
// 	ft_merge_sort(listdir, 0, listdir->book.cursor);
// }

int		main(int argc, char **argv)
{
	unsigned int	options;
	unsigned int	i;
	t_listdir		listdir;

	init_array_list(&(listdir.book));
	i = ft_options(&options, argv, argc);
	if (i < 1 || i == (unsigned int)argc)
		ft_printf(".\n");
	else
		ft_get_list(&argv[i], argc - i, &listdir);
	// ft_reader(&listdir, options);
	return (0);
}
