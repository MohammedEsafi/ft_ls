/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:04:30 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:29:31 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstrm_i(t_list **head, int i)
{
	t_list	*next;
	t_list	*tmp;

	if (head == NULL || *head == NULL)
		return ;
	if (i == 0)
	{
		ft_lstrm(head);
		return ;
	}
	tmp = *head;
	if (i == ft_lstcount(tmp) - 1)
	{
		ft_lstpop(tmp);
		return ;
	}
	if (i >= ft_lstcount(tmp))
		return ;
	while (--i > 0)
		tmp = tmp->next;
	next = tmp->next->next;
	free(tmp->next);
	tmp->next = next;
}
