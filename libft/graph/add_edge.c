/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:08:13 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/21 21:15:06 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <stdlib.h>

static t_node	*create_node(unsigned int vertex)
{
	t_node		*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->vertex = vertex;
	node->next = NULL;
	return (node);
}

void			add_edge(t_graph *graph, unsigned int src, unsigned int dest)
{
	t_node		*node;

	node = create_node(dest);
	node->next = graph->lists[src];
	graph->lists[src] = node;
	node = create_node(src);
	node->next = graph->lists[dest];
	graph->lists[dest] = node;
}
