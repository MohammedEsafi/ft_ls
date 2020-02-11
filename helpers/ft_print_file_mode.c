/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:45:34 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 14:01:14 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int		ft_case(mode_t mode, int i)
{
	if (i == 1 && mode & S_IXUSR)
		return (32);
	else if (i == 2 && mode & S_IXGRP)
		return (32);
	else if (i == 3 && mode & S_IXOTH)
		return (32);
	return (0);
}

void			ft_print_file_mode(t_datum *datum)
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
	(mode & S_ISUID) && (str[3] = 'S' + ft_case(mode, 1));
	(mode & S_IRGRP) && (str[4] = 'r');
	(mode & S_IWGRP) && (str[5] = 'w');
	(mode & S_IXGRP) && (str[6] = 'x');
	(mode & S_ISGID) && (str[6] = 'S' + ft_case(mode, 2));
	(mode & S_IROTH) && (str[7] = 'r');
	(mode & S_IWOTH) && (str[8] = 'w');
	(mode & S_IXOTH) && (str[9] = 'x');
	(mode & S_ISVTX) && (str[9] = 'T' + ft_case(mode, 3));
	ft_printf("%s", str);
	free(str);
}
