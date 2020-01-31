/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:20:19 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/18 20:36:03 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list		*pop(t_stack *stack)
{
	t_list	*tmp;

	if (stack->head == NULL)
		return (NULL);
	stack->size -= 1;
	tmp = stack->head;
	stack->head = stack->head->next;
	return (tmp);
}
