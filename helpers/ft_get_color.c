/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhaoui <aalhaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 10:59:39 by aalhaoui          #+#    #+#             */
/*   Updated: 2020/02/08 11:00:03 by aalhaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char			*ft_get_color(t_datum *datum, int opt)
{
	if (opt & COLOR)
	{
		if (S_ISDIR(datum->stat.st_mode) && (datum->stat.st_mode & S_IWOTH)
			&& !(datum->stat.st_mode & S_ISVTX))
			return (ft_strndup("\033[30;43m", 8));
		if (S_ISDIR(datum->stat.st_mode) && (datum->stat.st_mode & S_IWOTH)
			&& (datum->stat.st_mode & S_ISVTX))
			return (ft_strndup("\033[30;42m", 8));
		else if (S_ISDIR(datum->stat.st_mode))
			return (ft_strndup("\033[34m", 5));
		else if (S_ISLNK(datum->stat.st_mode))
			return (ft_strndup("\033[35m", 5));
		else if (S_ISSOCK(datum->stat.st_mode))
			return (ft_strndup("\033[32m", 5));
		else if (S_ISFIFO(datum->stat.st_mode))
			return (ft_strndup("\033[33m", 5));
		else if (S_IXUSR & datum->stat.st_mode)
			return (ft_strndup("\033[31m", 5));
		else if (S_ISBLK(datum->stat.st_mode))
			return (ft_strndup("\033[34;46m", 8));
		else if (S_ISCHR(datum->stat.st_mode))
			return (ft_strndup("\033[34;43m", 8));
	}
	return (ft_strndup("\0", 1));
}