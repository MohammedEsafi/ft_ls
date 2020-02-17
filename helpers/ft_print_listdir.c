/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_listdir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:25:34 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/17 08:32:08 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_unisolate(t_listdir *listdir, void **list)
{
	int		i;

	i = -1;
	while (list[++i] != NULL)
	{
		listdir->book.cursor += 1;
		listdir->book.list[listdir->book.cursor] = list[i];
	}
	free(list);
}

static void	**ft_isolate(t_listdir *listdir)
{
	void	**list;
	void	**temporary;
	int		i;
	int		j;
	int		k;

	list = (void **)malloc(sizeof(void *) * listdir->book.len);
	temporary = (void **)malloc(sizeof(void *) * listdir->book.len);
	i = -1;
	j = -1;
	k = -1;
	while (++i <= listdir->book.cursor)
	{
		if (!S_ISDIR(((t_datum *)(listdir->book.list[i]))->stat.st_mode))
			list[++j] = listdir->book.list[i];
		else
			temporary[++k] = listdir->book.list[i];
	}
	temporary[++k] = NULL;
	free(listdir->book.list);
	listdir->book.list = list;
	listdir->book.cursor = j;
	return (temporary);
}

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
	void		**temporary;

	if (bulb == TRUE && !(*listdir->options & FLAG_D))
		temporary = ft_isolate(listdir);
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
	if (bulb == TRUE && !(*listdir->options & FLAG_D))
		ft_unisolate(listdir, temporary);
	return (printed);
}
