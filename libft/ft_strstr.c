/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:35:19 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/13 22:35:23 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needle)
{
	char	*pkey;
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (!(*needle))
		return ((char *)str);
	while (*str)
	{
		pkey = ft_memchr(str, *needle, ft_strlen(str));
		if (!(pkey))
			return (0);
		if (ft_memcmp(needle, pkey, nlen) == 0)
			return (pkey);
		str = pkey + 1;
	}
	return (0);
}
