/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:25:05 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 14:11:50 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

void			init_array_list(t_array_list *arr)
{
	arr->list = (void **)malloc(sizeof(void *) * INITIAL_CAPACITY);
	arr->len = INITIAL_CAPACITY;
	arr->cursor = -1;
}
