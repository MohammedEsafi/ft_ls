/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:46:22 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/03 13:18:16 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	free_list_dir(t_listdir *listdir)
{
	int		i;
	t_datum	*item;

	free(listdir->parent);
	i = -1;
	while (++i <= listdir->book.cursor)
	{
		item = listdir->book.list[i];
		free(item->filename);
		free(item);
	}
	free(listdir->book.list);
	free(listdir);
}