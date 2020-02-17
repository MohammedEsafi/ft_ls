/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_lenght.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:24:00 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/15 18:58:09 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static size_t		*find_max_lenght_second_part(size_t *max_lenght,
		t_datum *datum)
{
	size_t		lenght;
	char		*tmp;
	char		*minor;
	char		*major;

	tmp = ft_itoa(datum->stat.st_nlink);
	lenght = ft_strlen(tmp);
	if (max_lenght[0] < lenght)
		max_lenght[0] = lenght;
	free(tmp);
	tmp = ft_itoa(datum->stat.st_size);
	lenght = ft_strlen(tmp);
	if (max_lenght[3] < lenght)
		max_lenght[3] = lenght;
	free(tmp);
	major = ft_itoa(major(datum->stat.st_rdev));
	minor = ft_itoa(minor(datum->stat.st_rdev));
	if (max_lenght[5] < ft_strlen(minor))
		max_lenght[5] = ft_strlen(minor);
	if (max_lenght[4] < ft_strlen(major))
		max_lenght[4] = ft_strlen(major);
	free(major);
	free(minor);
	return (max_lenght);
}

size_t				*find_max_lenght(t_listdir *listdir, int bulb)
{
	t_datum			*datum;
	struct group	*group_name;
	struct passwd	*user_name;
	size_t			*max_lenght;
	int				i;

	i = -1;
	max_lenght = (size_t *)ft_memalloc(sizeof(size_t) * 7);
	while (++i <= listdir->book.cursor)
	{
		datum = (t_datum *)(listdir->book.list[i]);
		user_name = getpwuid(datum->stat.st_uid);
		if (max_lenght[1] < ft_strlen(user_name->pw_name))
			(max_lenght[1] = ft_strlen(user_name->pw_name));
		group_name = getgrgid(datum->stat.st_gid);
		if (max_lenght[2] < ft_strlen(group_name->gr_name))
			(max_lenght[2] = ft_strlen(group_name->gr_name));
		find_max_lenght_second_part(max_lenght, datum);
		max_lenght[6] += datum->stat.st_blocks;
	}
	if (max_lenght[3] <= max_lenght[4] + max_lenght[5])
		max_lenght[3] = max_lenght[4] + max_lenght[5] + 2;
	if (!bulb && listdir->book.cursor != -1)
		ft_printf("total %d\n", max_lenght[6]);
	return (max_lenght);
}
