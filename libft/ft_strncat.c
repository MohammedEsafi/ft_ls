/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:11:15 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:31:22 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		dlen;

	dlen = ft_strlen(dest);
	ft_memccpy(dest + dlen, src, 0, n);
	n = n > ft_strlen(src) ? (dlen + ft_strlen(src)) : (dlen + n);
	*(dest + n) = '\0';
	return (dest);
}
