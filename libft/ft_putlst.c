/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:10:11 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:30:14 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *head)
{
	while (head)
	{
		ft_putstr(head->content);
		if (head->next)
			ft_putstr(" >> ");
		head = head->next;
	}
	ft_putchar('\n');
}
