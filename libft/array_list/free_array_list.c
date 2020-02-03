/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:45:53 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/03 13:20:33 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

void			free_array_list(t_array_list *arr)
{
	int		i;

	i = -1;
	while (++i <= arr->cursor)
		free(arr->list[i]);
	free(arr->list);
}
