/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 00:15:43 by aalhaoui          #+#    #+#             */
/*   Updated: 2020/02/06 10:51:44 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		ft_print_file_mode(t_datum *datum)
{
	mode_t	mode;
	char	*str;

	str = ft_strndup("----------", 10);
	mode = datum->stat.st_mode;
	(S_ISDIR(mode)) && (str[0] = 'd');
	(S_ISCHR(mode)) && (str[0] = 'c');
	(S_ISBLK(mode)) && (str[0] = 'b');
	(S_ISLNK(mode)) && (str[0] = 'l');
	(S_ISFIFO(mode)) && (str[0] = 'p');
	(S_ISSOCK(mode)) && (str[0] = 's');
	(mode & S_IRUSR) && (str[1] = 'r');
	(mode & S_IWUSR) && (str[2] = 'w');
	(mode & S_IXUSR) && (str[3] = 'x');
	(mode & S_IRGRP) && (str[4] = 'r');
	(mode & S_IWGRP) && (str[5] = 'w');
	(mode & S_IXGRP) && (str[6] = 'x');
	(mode & S_IROTH) && (str[7] = 'r');
	(mode & S_IWOTH) && (str[8] = 'w');
	(mode & S_IXOTH) && (str[9] = 'x');
	ft_printf("%s  ", str);
	free(str);
}

static void		ft_print_link_usr_grp(t_datum *datum, size_t *max_lenght, t_listdir *listdir)
{
	struct group	*group_name;
	struct passwd	*user_name;
	char			*buff_time;
	char			*buff_link;

	buff_link = (char *)malloc(sizeof(char) * 1024);
	ft_printf("%*d ", max_lenght[0], (int)datum->stat.st_nlink);
	if (!(FLAG_G & *listdir->options))
	{
		user_name = getpwuid(datum->stat.st_uid);
		(ft_printf("%-*s  ", max_lenght[1], user_name->pw_name));
	}
	group_name = getgrgid(datum->stat.st_gid);
	ft_printf("%-*s  ", max_lenght[2], group_name->gr_name);
	if (S_ISCHR(datum->stat.st_mode) || S_ISBLK(datum->stat.st_mode))
	{
		ft_printf("%*d, ", max_lenght[4], major(datum->stat.st_rdev));
		ft_printf("%*d ", max_lenght[5], minor(datum->stat.st_rdev));
	}
	else
		ft_printf("%*d ", max_lenght[3], (int)datum->stat.st_size);
	buff_time = ctime(&datum->stat.st_ctime);
	buff_time[16] = '\0';
	ft_printf("%s ", buff_time + 4);
	if (!S_ISLNK(datum->stat.st_mode) || (readlink(datum->path, buff_link, 1024) == -1))
		ft_printf("%-s\n", datum->filename);
	else
		ft_printf("%-s -> %s\n", datum->filename, buff_link);
	free(buff_link);
}

int			ft_print_flag_list(t_listdir *listdir, size_t *max_lenght, int i)
{
	t_datum		*datum;

	datum = (t_datum *)(listdir->book.list[i]);
	ft_print_file_mode(datum);
	ft_print_link_usr_grp(datum, max_lenght, listdir);
	return (1);
}
