/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:58:19 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:29:28 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstrm(t_list **head)
{
	t_list	*tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
