/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:11:29 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 09:11:45 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int					is_link(char *parent, char *filename)
{
	char			*buff_link;
	char			*path;
	char			*tmp;
	struct stat		stat;
	int				len;

	len = ft_strlen(filename);
	if (filename[len - 1] == '/')
	{
		tmp = ft_strndup(filename, len - 1);
		path = ft_join_path(parent, tmp);
		free(tmp);
	}
	else
		path = ft_join_path(parent, filename);
	buff_link = (char *)ft_memalloc(sizeof(char) * 1024);
	len = readlink(path, buff_link, 1024);
	free(path);
	lstat(buff_link, &stat);
	free(buff_link);
	if (len == -1)
		return (1);
	if (S_ISLNK(stat.st_mode))
		return (0);
	return (1);
}
