/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhaoui <aalhaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:24:07 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/10 19:36:40 by aalhaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		ft_usage(char ch)
{
	ft_printf("ls: illegal option -- %c\n", ch);
	ft_printf("usage: ls [-%s] [file ...]\n", OPTS);
	exit(2);
}

static void		ft_get_opt(char *str, unsigned int *opt)
{
	unsigned int	i;

	i = 0;
	while (str[++i])
	{
		if (ft_strchr(OPTS, str[i]) == NULL)
			ft_usage(str[i]);
		(str[i] == 'l') && (*opt = (*opt & ~FLAG_1) | LIST);
		(str[i] == 'R') && (*opt |= RECURSIVE);
		(str[i] == 'a') && (*opt |= ALL);
		(str[i] == 'r') && (*opt |= REVERSE);
		(str[i] == 't') && (*opt |= TIME);
		(str[i] == 'f') && (*opt |= FLAG_F);
		(str[i] == 'g') && (*opt |= FLAG_G);
		(str[i] == 'd') && (*opt |= FLAG_D);
		(str[i] == '1') && (*opt = (*opt & ~LIST) | FLAG_1);
		(str[i] == 'G') && (*opt |= COLOR);
		(str[i] == 'm') && (*opt |= FLAG_M);
	}
}

int				ft_options(unsigned int *options, char **argv, int len)
{
	int	i;

	i = 0;
	while (++i < len && argv[i][0] == '-')
	{
		if (ft_strequ(argv[i], "-"))
			return (i);
		else if (ft_strequ(argv[i], "--"))
			return (++i);
		ft_get_opt(argv[i], options);
	}
	return (i);
}
