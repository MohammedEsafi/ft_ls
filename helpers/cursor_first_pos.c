/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_first_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:01:54 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/06 11:03:39 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int			cursor_first_pos(void)
{
	struct termios	config;
    char    posetion[20];
    int     i;
	int		y;

	y = 0;
	tcgetattr(0, &config);
	config.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, 0, &config);
	ft_putstr_fd("\e[6n", 0);
    i = read(0, posetion, 20);
    posetion[i] = 0;
    i = 2;
    y = ft_atoi(posetion + i) - 1;
	tcgetattr(0, &config);
	config.c_lflag |= (ECHO | ICANON);
	tcsetattr(0, 0, &config);
    return (y);
}
