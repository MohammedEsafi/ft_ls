/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:28:29 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/18 20:35:48 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_list		*dequeue(t_queue *queue)
{
	t_list	*tmp;

	if (queue->front == NULL)
		return (NULL);
	queue->size -= 1;
	tmp = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->last = NULL;
	return (tmp);
}
