/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:59:28 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/19 18:35:57 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *stack, t_list *node)
{
	stack->size += 1;
	if (stack->head == NULL)
	{
		stack->head = node;
		return ;
	}
	node->next = stack->head;
	stack->head = node;
}
