/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:00:17 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:29:00 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_i(t_list **head, t_list *new, int i)
{
	t_list	*next;
	t_list	*tmp;

	if (head == NULL || *head == NULL)
		return ;
	if (i == 0)
	{
		ft_lstadd(head, new);
		return ;
	}
	tmp = *head;
	if (i > ft_lstcount(tmp))
		return ;
	while (--i > 0)
		tmp = tmp->next;
	next = tmp->next;
	tmp->next = new;
	new->next = next;
}
