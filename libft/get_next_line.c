/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:31:59 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/13 22:29:02 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_newnode(int fd, t_lst **node)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->fd = fd;
	if (!(new->res = ft_strnew(0)))
		return (NULL);
	new->next = *node;
	*node = new;
	return (new);
}

t_lst	*ft_lstsearch(int fd, t_lst *node)
{
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	return (NULL);
}

char	*ft_secure_join(char *s1, char *s2, int end, int option)
{
	char	*str;

	str = NULL;
	if (option == 0)
	{
		s2[end] = '\0';
		if (*s2 == '\0')
			return (s1);
		if (!(str = ft_strjoin(s1, s2)))
			return (NULL);
		free(s1);
	}
	else
	{
		if (s1 != NULL)
		{
			if (!(str = ft_strdup(s1 + 1)))
				return (NULL);
			free(s2);
		}
		else
			free(s2);
	}
	return (str);
}

int		ft_freenode(t_lst **head, int fd)
{
	t_lst	*tmp;
	t_lst	*prev;

	tmp = *head;
	prev = NULL;
	while (tmp->fd != fd && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->fd == fd)
	{
		if (prev)
			prev->next = tmp->next;
		else
			*head = tmp->next;
		free(tmp->res);
		free(tmp);
		return (-1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*head = NULL;
	char			buf[BUFF_SIZE + 1];
	int				count;
	t_lst			*node;
	char			*snap;

	if (!line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!(node = ft_lstsearch(fd, head)))
		if (!(node = ft_newnode(fd, &head)))
			return (-1);
	while (node->res != NULL && !(snap = ft_strchr(node->res, '\n'))
		&& ((count = read(fd, buf, BUFF_SIZE)) > 0))
		if (!(node->res = ft_secure_join(node->res, buf, count, 0)))
			return (ft_freenode(&head, fd));
	if ((node->res == NULL || *(node->res) == '\0') && ft_freenode(&head, fd))
		return (0);
	if (node->res != NULL && snap)
		*snap = '\0';
	if (node->res && !(*line = ft_strdup(node->res)))
		return (ft_freenode(&head, fd));
	if (!(node->res = ft_secure_join(snap, node->res, 0, 1)) && snap)
		return (ft_freenode(&head, fd));
	return (1);
}
