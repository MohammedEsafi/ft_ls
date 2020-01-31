/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:04:58 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:31:01 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int n;

	n = 0;
	if (s != NULL && f != NULL)
	{
		while (*s)
		{
			f(n, s);
			s++;
			n++;
		}
	}
}
