/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:31:19 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:31:15 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	size_t	i;
	size_t	n;

	if (!s || !f)
		return (NULL);
	n = ft_strlen(s);
	p = ft_strnew(n);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = f(s[i]);
		i++;
	}
	return (p);
}
