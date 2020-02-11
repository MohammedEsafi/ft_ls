/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhaoui <aalhaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:28:19 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/11 20:32:53 by aalhaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char		*ft_join_path(char *parent, char *child)
{
	char	*full_path;
	int		p_len;
	int		c_len;

	p_len = ft_strlen(parent);
	c_len = ft_strlen(child);
	if (p_len == 1 && parent[0] == '/')
		p_len = 0;
	if (parent == NULL)
	{
		if (!(full_path = (char *)malloc(c_len + 1)))
			return (NULL);
		ft_memcpy(full_path, child, c_len + 1);
	}
	else
	{
		if (!(full_path = (char *)malloc(p_len + c_len + 2)))
			return (NULL);
		ft_memcpy(full_path, parent, p_len);
		ft_memcpy(full_path + p_len, "/", 1);
		ft_memcpy(full_path + p_len + 1, child, c_len + 1);
	}
	return (full_path);
}
