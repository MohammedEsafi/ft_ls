/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:01:04 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/03 11:46:40 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		compare_string(char *str1, char *str2, unsigned int opt)
{
	int		i;
	int		answer;

	i = 0;
	answer = !(opt & REVERSE);
	while (TRUE)
	{
		if (str1[i] < str2[i])
			return (answer);
		else if (str1[i] > str2[i])
			return (!answer);
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
		++i;
	}
	return (!answer);
}

int		compare_time(t_datum *d1, t_datum *d2, unsigned int opt)
{
	int		answer;

	answer = !(opt & REVERSE);
	if (d1->stat.st_mtime < d2->stat.st_mtime)
		return (!answer);
	return (answer);
}

int		ft_opt_sort(void **list, int i, int j, unsigned int *options)
{
	if (options == NULL)
		return (compare_string(list[i], list[j], 0));
	else if (*options & TIME)
		return (compare_time((t_datum *)list[i], (t_datum *)list[j], *options));
	else
		return (compare_string(((t_datum *)list[i])->filename,
					((t_datum *)list[j])->filename, *options));
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
