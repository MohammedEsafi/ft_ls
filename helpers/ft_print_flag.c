/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 03:40:55 by aalhaoui          #+#    #+#             */
/*   Updated: 2020/02/17 19:24:57 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static	size_t	find_max_lenght_of_files(t_listdir *listdir)
{
	size_t		result;
	t_datum		*datum;
	size_t		lenght;
	int			i;

	result = 0;
	i = -1;
	while (++i <= listdir->book.cursor)
	{
		datum = (t_datum *)(listdir->book.list[i]);
		lenght = ft_strlen(datum->filename);
		if (result < lenght)
			result = lenght;
	}
	return (result + 1);
}

int				*ft_get_parameter(t_listdir *listdir)
{
	struct winsize	window;
	size_t			width_max;
	int				*max_row_col;
	int				number_files;

	max_row_col = (int *)malloc(sizeof(int) * 5);
	number_files = (listdir->book.cursor > 0) ? listdir->book.cursor : 0;
	ioctl(1, TIOCGWINSZ, &window);
	width_max = find_max_lenght_of_files(listdir);
	max_row_col[0] = (window.ws_col / width_max > 0) ?
		window.ws_col / width_max : 1;
	max_row_col[1] = number_files / max_row_col[0] + 1;
	max_row_col[2] = width_max;
	max_row_col[3] = number_files / max_row_col[1];
	max_row_col[4] = number_files % max_row_col[1] + 1;
	return (max_row_col);
}

int				ft_print_flag_non_list(t_listdir *listdir, int i,
				t_col *d, char *color)
{
	static int		last_y;
	static int		all_av;
	struct winsize	window;
	t_datum			*datum;
	static int		ret;

	datum = (t_datum *)(listdir->book.list[i]);
	ioctl(1, TIOCGWINSZ, &window);
	all_av++;
	(d->y > last_y) && (last_y = d->y);
	ft_printf("\e[%d;%dH", d->y + 1, d->x + 1);
	ft_printf("%s%s%s", color, datum->filename, (*listdir->options & COLOR) ?
			"\033[0m" : "\0");
	if ((last_y >= (window.ws_row - 1)) &&
		(d->x == d->max_row_col[3] * d->max_row_col[2])
			&& all_av < listdir->book.cursor + 1)
	{
		ret = -1;
		ft_putchar('\n');
	}
	if (all_av == listdir->book.cursor && last_y++)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, last_y + 1), 1);
	return (ret);
}
