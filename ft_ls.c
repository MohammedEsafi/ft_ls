/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:13:56 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/04 19:37:20 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	listdir->max_lenght = NULL;
	ft_reader(listdir, TRUE);
	return (0);
}
