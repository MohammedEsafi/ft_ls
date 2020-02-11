/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhaoui <aalhaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:31:41 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 19:34:32 by aalhaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

static void		grow_size(t_array_list *arr)
{
	void	**new_list;

	new_list = (void **)malloc(sizeof(void *) * (INITIAL_CAPACITY + arr->len));
	ft_memcpy(new_list, arr->list, sizeof(void *) * arr->len);
	arr->len += INITIAL_CAPACITY;
	free(arr->list);
	arr->list = new_list;
}

void			append(t_array_list *arr, void *p)
{
	if (arr->list == NULL || p == NULL)
		return ;
	arr->cursor += 1;
	if (arr->cursor == arr->len)
		grow_size(arr);
	arr->list[arr->cursor] = p;
}
