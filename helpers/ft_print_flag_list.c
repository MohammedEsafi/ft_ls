/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 00:15:43 by aalhaoui          #+#    #+#             */
/*   Updated: 2020/02/11 14:10:16 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static	void	ft_print_time(t_datum *datum)
{
	char			*buff_time;
	unsigned int	six_month;
	char			*buff;

	six_month = 15724800;
	if (six_month < time(NULL) - datum->stat.st_mtime)
	{
		buff_time = ctime(&datum->stat.st_ctime);
		buff = ft_strsub(buff_time, 20, 4);
		buff_time[10] = '\0';
		ft_printf("%s %5s ", buff_time + 4, buff);
		ft_strdel(&buff);
	}
	else
	{
		buff_time = ctime(&datum->stat.st_ctime);
		buff_time[16] = '\0';
		ft_printf("%s ", buff_time + 4);
	}
}

static void		ft_print_size_time_name(t_datum *datum, size_t *max_lenght,
					t_listdir *listdir, char *color)
{
	char	*buff_link;
	char	*rest;

	rest = (*listdir->options & COLOR) ? "\033[0m" : "\0";
	if (!(buff_link = (char *)ft_memalloc(sizeof(char) * 1024)))
		return ;
	if (S_ISCHR(datum->stat.st_mode) || S_ISBLK(datum->stat.st_mode))
	{
		ft_printf("%*d, ", max_lenght[4], major(datum->stat.st_rdev));
		ft_printf("%*d ", max_lenght[5], minor(datum->stat.st_rdev));
	}
	else
		ft_printf("%*d ", max_lenght[3], (int)datum->stat.st_size);
	ft_print_time(datum);
	if (!S_ISLNK(datum->stat.st_mode) ||
		(readlink(datum->path, buff_link, 1024) == -1))
		ft_printf("%s%-s%s\n", color, datum->filename, rest);
	else
		ft_printf("%s%-s%s -> %s\n", color, datum->filename, rest, buff_link);
	free(buff_link);
}

static void		ft_print_link_usr_grp(t_datum *datum, size_t *max_lenght,
					t_listdir *listdir)
{
	struct group	*group_name;
	struct passwd	*user_name;

	ft_printf("%*d ", max_lenght[0], (int)datum->stat.st_nlink);
	if (!(FLAG_G & *listdir->options))
	{
		user_name = getpwuid(datum->stat.st_uid);
		(ft_printf("%-*s  ", max_lenght[1], user_name->pw_name));
	}
	group_name = getgrgid(datum->stat.st_gid);
	ft_printf("%-*s  ", max_lenght[2], group_name->gr_name);
}

int				ft_print_flag_list(t_listdir *listdir, size_t *max_lenght,
					int i, char *color)
{
	t_datum		*datum;

	datum = (t_datum *)(listdir->book.list[i]);
	ft_print_file_mode(datum);
	ft_print_link_usr_grp(datum, max_lenght, listdir);
	ft_print_size_time_name(datum, max_lenght, listdir, color);
	return (1);
}
