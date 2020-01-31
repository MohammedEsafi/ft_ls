/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:56:17 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:31:52 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (len--)
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
