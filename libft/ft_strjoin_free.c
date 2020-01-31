/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:59:59 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/21 21:00:02 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int option)
{
	char	*str;

	if (s2 == NULL || *s2 == 0)
		str = ft_strdup(s1);
	else if (s1 == NULL || *s1 == 0)
		str = ft_strdup(s2);
	else
		str = ft_strjoin(s1, s2);
	if (option == 1 || option == 0)
		if (s1 != NULL)
			free((void *)s1);
	if (option == 2 || option == 0)
		if (s2 != NULL)
			free((void *)s2);
	return (str);
}
