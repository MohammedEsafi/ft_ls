/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:14:37 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 12:18:36 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <stdio.h>

void		print_graph(t_graph *graph)
{
	unsigned int	i;
	t_node			*temp;

	i = 0;
	while (i < graph->num_vertices)
	{
		temp = graph->lists[i];
		ft_putnbr(i);
		ft_putstr(": ( ");
		while (temp)
		{
			ft_putnbr(temp->vertex);
			temp = temp->next;
			if (temp != NULL)
				ft_putchar(',');
			ft_putchar(' ');
		}
		ft_putstr(")\n");
		++i;
	}
}
