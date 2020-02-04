/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:24:07 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/03 20:03:15 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		ft_get_opt(char *str, unsigned int *opt)
{
	unsigned int	i;

	i = 0;
	while (str[++i])
	{
		if (ft_strchr(OPTS, str[i]) == NULL)
		{
			ft_printf("ls: illegal option -- %c\n", str[i]);
			ft_printf("usage: ls [-%s] [file ...]\n", OPTS);
			exit(2);
		}
		if (str[i] == 'l')
			*opt |= LIST;
		else if (str[i] == 'R')
			*opt |= RECURSIVE;
		else if (str[i] == 'a')
			*opt |= ALL;
		else if (str[i] == 'r')
			*opt |= REVERSE;
		else if (str[i] == 't')
			*opt |= TIME;
		else if (str[i] == 'f')
			*opt |= FLAG_F;
		else if (str[i] == 'g')
			*opt |= FLAG_G;
		else if (str[i] == 'd')
			*opt |= FLAG_D;
	}
}

int	ft_options(unsigned int *options, char **argv, int len)
{
	int	i;

	i = 0;
	while (++i < len && argv[i][0] == '-')
	{
		if (argv[i][1] == '-')
			return (++i);
		ft_get_opt(argv[i], options);
	}
	return (i);
}
