/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:17:41 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:29:54 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src - dest > 0)
		ft_memcpy(dest, src, n);
	else if (src - dest < 0)
		while (n)
		{
			*(unsigned char *)(dest + n - 1) = *(unsigned char *)(src + n - 1);
			n--;
		}
	return (dest);
}
