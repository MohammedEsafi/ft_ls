/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:13:56 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/31 16:01:04 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_not_found(t_stack *not_found)
{
	t_list	*node;

	while (not_found->size != 0)
	{
		node = pop(&not_found);
		ft_printf(">> %s\n", (char *)(node->content));
	}
}

void	ft_get_list(char **argv, int len, t_listdir *listdir)
{
	int		i;
	t_list	*node;
	t_datum	*element;
	t_datum	datum;
	t_stack	not_found;

	i = -1;
	while (++i < len)
	{
		if (lstat(argv[i], &(datum.stat)) == -1)
		{
			node = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1);
			push(&not_found, node);
		}
		else
		{
			datum.filename = argv[i];
			node = ft_lstnew(&datum, sizeof(t_datum));
			push(&(listdir->elements), node);
		}
	}
	ft_not_found(&not_found);
}

int		main(int argc, char **argv)
{
	unsigned int	options;
	unsigned int	i;
	t_listdir		listdir;

	init_stack(&(listdir.elements));
	init_array_list(&(listdir.book));
	i = ft_options(&options, argv, argc);
	if (i < 1 || i == (unsigned int)argc)
		ft_printf(".\n");
	else
		ft_printf("read data from argv\n");
	ft_get_list(&argv[i], argc - i, &listdir);



	// DIR				*d;
	// struct dirent	*dirent;
	// struct stat		path_stat;

	// if (argc != 2)
	// 	ft_read(NULL, 0);
	// (void)argv;
	// d = opendir("/libft");
	// ft_printf("%d", d->__dd_len);
	// if (d == NULL)
	// 	ft_printf("dd\n");
	// // while ((dirent = readdir(d)) && dirent != NULL)
	// // {
	// // 	ft_printf("%s\n", dirent->d_name);
	// // 	ft_printf("%d\n", dirent->d_type);
	// // }
	// stat("ft_ls.c", &path_stat);
	// ft_printf("%d\n", S_ISREG(path_stat.st_mode));
	return (0);
}
