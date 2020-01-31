/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 00:38:46 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:30:21 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	b;

	if (n < 0)
	{
		if (n <= -10)
			ft_putnbr_fd(n / 10, fd);
		else
			write(fd, "-", 1);
		b = (n % 10) * -1 + '0';
		write(fd, &b, 1);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		b = (n % 10) + '0';
		write(fd, &b, 1);
	}
}
