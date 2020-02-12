/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:05:07 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/12 17:59:57 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int	compare_string(char *str1, char *str2, unsigned int opt)
{
	int		i;
	int		answer;

	i = 0;
	answer = !(opt & REVERSE);
	while (TRUE)
	{
		if (str1[i] < str2[i])
			return (answer);
		else if (str1[i] > str2[i])
			return (!answer);
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
		++i;
	}
	return (!answer);
}

int	compare_time(t_datum *d1, t_datum *d2, unsigned int opt)
{
	int		answer;

	answer = !(opt & REVERSE);
	if (d1->stat.st_mtime <= d2->stat.st_mtime)
		return (!answer);
	return (answer);
}
