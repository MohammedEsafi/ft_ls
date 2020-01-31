/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:32:27 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/19 21:32:46 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_stack(t_stack *stack)
{
	t_list	*node;

	while (stack->size != 0)
	{
		node = pop(stack);
		free(node->content);
		free(node);
	}
}
