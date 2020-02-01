/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:13:56 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/01 14:48:33 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_listdir(t_listdir *listdir)
{
	int		i;

	i = -1;
	while (++i <= listdir->book.cursor)
	{
		ft_printf("%s\n", ((t_datum *)(listdir->book.list[i]))->filename);
	}
}

void	ft_reader(t_listdir *listdir, int first_time)
{
	// DIR		*d;

	ft_merge_sort(listdir, 0, listdir->book.cursor);
	ft_print_listdir(listdir);

	(void)first_time;
}

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
	listdir.options = &options;
	ft_reader(&listdir, TRUE);
	return (0);
}
