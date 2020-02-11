/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:23:57 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 09:24:16 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			ft_router(t_listdir *listdir, t_datum *datum, int i, t_col *d)
{
	char	*color;
	char	*rest;

	rest = (*listdir->options & COLOR) ? "\033[0m" : "\0";
	if ((LIST | FLAG_G | FLAG_1 | FLAG_M) & *listdir->options)
		color = ft_get_color(datum, *listdir->options);
	if (FLAG_M & *listdir->options)
	{
		if (i != listdir->book.cursor)
			ft_printf("%s%s, %s", color, datum->filename, rest);
		else
			ft_printf("%s%s%s", color, datum->filename, rest);
	}
	else if ((LIST | FLAG_G) & *listdir->options)
		ft_print_flag_list(listdir, listdir->max_lenght, i, color);
	else if (FLAG_1 & *listdir->options)
		ft_printf("%s%s%s\n", color, datum->filename, rest);
	else
	{
		(d->index > listdir->book.cursor) && (d->index = ++d->last_index);
		color = ft_get_color(listdir->book.list[d->index], *listdir->options);
		ft_print_column(listdir, d, color);
	}
	free(color);
}
