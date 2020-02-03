/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhaoui <aalhaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 00:15:43 by aalhaoui          #+#    #+#             */
/*   Updated: 2020/02/03 01:46:53 by aalhaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static size_t		*find_max_lenght_second_part(size_t *max_lenght, t_datum *datum)
{
	size_t		lenght;
	char		*tmp;
	char		*minor;
	char		*major;

	tmp = ft_itoa(datum->stat.st_nlink);
	lenght = ft_strlen(tmp);
	if (max_lenght[0] < lenght)
		max_lenght[0] = lenght;
	free(tmp);
	tmp = ft_itoa(datum->stat.st_size);
	lenght = ft_strlen(tmp);
	if (max_lenght[3] < lenght)
		max_lenght[3] = lenght;
	free(tmp);
	major = ft_itoa(major(datum->stat.st_rdev));
	minor = ft_itoa(minor(datum->stat.st_rdev));
	if (max_lenght[5] < ft_strlen(minor))
		max_lenght[5] = ft_strlen(minor);
	if (max_lenght[4] < ft_strlen(major))
		max_lenght[4] = ft_strlen(major);
	free(major);
	free(minor);
	return (max_lenght);
}

size_t		*find_max_lenght(t_listdir *listdir, size_t *max_lenght)
{
	t_datum			*datum;
	struct group	*group_name;
	struct passwd	*user_name;
	int				i;

	i = -1;
	while (++i <= listdir->book.cursor)
	{
		datum = (t_datum *)(listdir->book.list[i]);
		user_name = getpwuid(datum->stat.st_uid);
		if (max_lenght[1] < ft_strlen(user_name->pw_name))
			(max_lenght[1] = ft_strlen(user_name->pw_name));
		group_name = getgrgid(datum->stat.st_gid);
		if (max_lenght[2] < ft_strlen(group_name->gr_name))
			(max_lenght[2] = ft_strlen(group_name->gr_name));
		find_max_lenght_second_part(max_lenght, datum);
		max_lenght[6] += datum->stat.st_blocks;
	}
	if ((max_lenght[4] != 0 || max_lenght[5] != 0) &&
		max_lenght[3] < max_lenght[4] + max_lenght[5] + 2)
		max_lenght[3] = max_lenght[4] + max_lenght[5] + 2;
	return (max_lenght);
}

static void		ft_print_file_mode(t_datum *datum)
{
	mode_t	mode;
	char	*str;

	str = (char *)malloc(sizeof(char) * 10);
	str = ft_strcpy(str, "----------");
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
	if (!(FLAG_G && listdir->options))
	{
		user_name = getpwuid(datum->stat.st_uid);
		(ft_printf("%-*s  ", max_lenght[1], user_name->pw_name));
	}
	group_name = getgrgid(datum->stat.st_gid);
	ft_printf("%-*s  ", max_lenght[2], group_name->gr_name);
	if (S_ISCHR(datum->stat.st_mode) || S_ISBLK(datum->stat.st_mode))
	{
		ft_printf("%*d, ", max_lenght[5], major(datum->stat.st_rdev));
		ft_printf("%*d ", max_lenght[6], minor(datum->stat.st_rdev));
	}
	else
		ft_printf("%*d ", max_lenght[3], (int)datum->stat.st_size);
	buff_time = ctime(&datum->stat.st_ctime);
	buff_time[16] = '\0';
	ft_printf("%s ", buff_time + 4);
	if (!(S_ISLNK(datum->stat.st_mode) && (readlink(listdir->parent, buff_link, 1024) > 0)))
		ft_printf("%-s\n", datum->filename);
	if (S_ISLNK(datum->stat.st_mode) && (readlink(listdir->parent, buff_link, 1024) > 0))
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
