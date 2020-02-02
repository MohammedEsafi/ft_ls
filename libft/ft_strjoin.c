/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 23:12:39 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/01 19:34:14 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	p = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, s1len);
	ft_memcpy(p + s1len, s2, s2len);
	p[s1len + s2len] = '\0';
	return (p);
}
