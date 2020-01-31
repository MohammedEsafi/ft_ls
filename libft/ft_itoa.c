/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:12:26 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:28:52 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	number_of_digits(int n)
{
	int		count;

	count = n <= 0 ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_swap(char *a, char *b)
{
	char	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

static char	*ft_reverse(char *buffer, int i, int j)
{
	while (i < j)
		ft_swap(&buffer[i++], &buffer[j--]);
	return (buffer);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		sign;
	int		digits_numbers;

	digits_numbers = number_of_digits(n);
	sign = (n < 0) ? -1 : 1;
	num = (char *)malloc((digits_numbers + 1) * sizeof(char));
	if (!num)
		return (NULL);
	if (n == 0)
		*num++ = '0';
	while (n != 0)
	{
		*num = (n % 10) * sign + '0';
		num++;
		n /= 10;
	}
	if (sign == -1)
		*num++ = '-';
	*num = '\0';
	return (ft_reverse(num - digits_numbers, 0, digits_numbers - 1));
}
