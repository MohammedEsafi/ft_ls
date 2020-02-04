/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:28:19 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/03 18:46:04 by mesafi           ###   ########.fr       */
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
		full_path = (char *)malloc(c_len + 1);
		ft_memcpy(full_path, child, c_len + 1);
	}
	else
	{
		full_path = (char *)malloc(p_len + c_len + 2);
		ft_memcpy(full_path, parent, p_len);
		ft_memcpy(full_path + p_len, "/", 3);
		ft_memcpy(full_path + p_len + 1, child, c_len + 1);
	}
	return (full_path);
}
