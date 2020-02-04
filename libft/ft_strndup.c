/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:28:33 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/04 09:31:47 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, int len)
{
	char	*sdup;

	sdup = (char *)malloc((len + 1) * sizeof(char));
	if (!sdup)
		return (NULL);
	ft_memcpy(sdup, s1, len);
	sdup[len] = '\0';
	return (sdup);
}
