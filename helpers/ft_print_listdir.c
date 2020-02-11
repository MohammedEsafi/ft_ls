/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_listdir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:25:34 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 09:33:46 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	init_t_col(t_col *data, t_listdir *listdir)
{
	data->x = 0;
	data->y = cursor_first_pos();
	data->index = 0;
	data->last_index = 0;
	data->max_row_col = ft_get_parameter(listdir);
	data->tmp = 0;
	data->tmp1 = 0;
}

static void	ft_loop(t_listdir *listdir, t_col *data, int bulb, int *printed)
{
	int			i;
	t_datum		*datum;

	i = -1;
	while (++i <= listdir->book.cursor)
	{
		datum = (t_datum *)(listdir->book.list[i]);
		if (bulb == TRUE)
		{
			if (!S_ISDIR(datum->stat.st_mode) || (*listdir->options & FLAG_D))
			{
				if (S_ISLNK(datum->stat.st_mode) && !(LIST & *listdir->options))
					continue ;
				ft_router(listdir, datum, i, data);
				++(*printed);
			}
		}
		else
		{
			ft_router(listdir, datum, i, data);
			*printed = 1;
		}
	}
}

int			ft_print_listdir(t_listdir *listdir, int bulb)
{
	int			printed;
	t_col		data;

	printed = 0;
	data.max_row_col = NULL;
	if (!((LIST | FLAG_G | FLAG_1 | FLAG_M) & *listdir->options))
		init_t_col(&data, listdir);
	if ((LIST | FLAG_G) & *listdir->options)
		listdir->max_lenght = find_max_lenght(listdir, bulb);
	ft_loop(listdir, &data, bulb, &printed);
	if (!((LIST | FLAG_G | FLAG_1) & *listdir->options) && printed != 0)
		write(1, "\n", 1);
	if (data.max_row_col != NULL)
		free(data.max_row_col);
	return (printed);
}
