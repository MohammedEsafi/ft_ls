/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:13:44 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 09:16:35 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_print_column(t_listdir *listdir, t_col *d, char *color)
{
	d->tmp = ft_print_flag_non_list(listdir, d->index, d, color);
	d->index += d->max_row_col[1];
	if (d->x == (d->max_row_col[3]) * d->max_row_col[2])
	{
		if (d->tmp1 + 1 == d->max_row_col[4])
			d->max_row_col[3] -= 1;
		d->x = 0;
		if (d->tmp != -1)
		{
			d->tmp1++;
			d->y++;
		}
		else
			d->tmp1++;
	}
	else
		d->x += d->max_row_col[2];
}
