/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:01:04 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/01 11:53:20 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		compare_strings(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (TRUE)
	{
		if (str1[i] < str2[i])
			return (1);
		else if (str1[i] > str2[i])
			return (0);
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
		++i;
	}
	return (0);
}

int		ft_opt_sort(void **list, int i, int j, unsigned int *options)
{
	if (options == NULL)
		return (compare_strings(list[i], list[j]));
	return (0);
}

void	ft_merge(t_listdir *listdir, int left, int middle, int right)
{
	void	**temporal;
	int		l1;
	int		l2;
	int		i;

	temporal = (void **)malloc(sizeof(void *) * (right - left + 1));
	l1 = left - 1;
	l2 = middle;
	i = -1;
	while (l1 < middle && l2 < right)
	{
		if (ft_opt_sort(listdir->book.list, l1 + 1, l2 + 1, listdir->options) == 1)
			temporal[++i] = listdir->book.list[++l1];
		else
			temporal[++i] = listdir->book.list[++l2];
	}
	while (l1 < middle)
		temporal[++i] = listdir->book.list[++l1];
	while (l2 < right)
		temporal[++i] = listdir->book.list[++l2];
	i = -1;
	while (left <= right)
	{
		listdir->book.list[left] = temporal[++i];
		++left;
	}
	free(temporal);
}

void	ft_merge_sort(t_listdir *listdir, int left, int right)
{
	int		middle;

	if (left < right)
	{
		middle = (left + right) / 2;
		ft_merge_sort(listdir, left, middle);
		ft_merge_sort(listdir, middle + 1, right);
		ft_merge(listdir, left, middle, right);
	}
}
