/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 06:43:56 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:29:16 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	node = f(lst);
	if (node == NULL)
	{
		ft_lstdel(&begin, &ft_del);
		return (NULL);
	}
	begin = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = f(lst);
		node = node->next;
		if (node == NULL)
		{
			ft_lstdel(&begin, &ft_del);
			return (NULL);
		}
	}
	return (begin);
}
