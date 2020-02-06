/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 03:40:55 by aalhaoui          #+#    #+#             */
/*   Updated: 2020/02/06 11:42:58 by mesafi           ###   ########.fr       */
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

int			*ft_get_parameter(t_listdir *listdir)
{
	struct winsize	window;
	size_t			width_max;
	int				*max_row_col;
	int				number_files;

	max_row_col = (int *)malloc(sizeof(int) * 5);
	number_files = listdir->book.cursor;
	ioctl(1, TIOCGWINSZ, &window);
	width_max = find_max_lenght_of_files(listdir);
	max_row_col[0] = window.ws_col / width_max;
	max_row_col[1] = number_files / max_row_col[0] + 1;
	max_row_col[2] = width_max;
	max_row_col[3] = number_files / max_row_col[1];
	max_row_col[4] = number_files % max_row_col[1] + 1;
	return (max_row_col);
}

int		ft_print_flag_non_list(int x, int y, t_listdir *listdir, int i)
{
	static int 		last_y;
	static int 		all_av;
	struct winsize	window;
	int			*max_row_col;
	t_datum		*datum;
	static int 		ret;

	datum = (t_datum *)(listdir->book.list[i]);
	ioctl(1, TIOCGWINSZ, &window);
	all_av++;
	max_row_col = ft_get_parameter(listdir);
	(y > last_y) && (last_y = y);
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, y), 1);
	write(1, datum->filename, ft_strlen(datum->filename));
	if ((last_y == (window.ws_row - 1)) && (x == max_row_col[3] * max_row_col[2]))
	{
		ret = -1;
		ft_putchar('\n');
	}
	if (all_av == listdir->book.cursor && last_y++)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, last_y + 1), 1);
	return (ret);
}