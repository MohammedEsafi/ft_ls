/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:03:03 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 12:07:24 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <stdlib.h>

t_graph		*create_graph(unsigned int vertices)
{
	t_graph			*graph;
	unsigned int	i;

	graph = (t_graph *)malloc(sizeof(t_graph));
	graph->num_vertices = vertices;
	graph->lists = (t_node **)malloc(sizeof(t_node *) * vertices);
	i = 0;
	while (i < vertices)
	{
		graph->lists[i] = NULL;
		++i;
	}
	return (graph);
}
