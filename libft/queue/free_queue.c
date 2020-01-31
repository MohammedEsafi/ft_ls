/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:31:38 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/19 21:32:08 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	free_queue(t_queue *queue)
{
	t_list	*node;

	while (queue->size != 0)
	{
		node = dequeue(queue);
		free(node->content);
		free(node);
	}
}
