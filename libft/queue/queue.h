/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:37:20 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/21 21:16:18 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H

/*
 ** Definitions
*/

# define QUEUE_H

/*
 ** Includes
*/

# include "../libft.h"

/*
 ** Structures
*/

typedef struct	s_queue
{
	struct s_list	*front;
	struct s_list	*last;
	unsigned int	size;
}				t_queue;

/*
 ** Queue Functions
*/

void			init_queue(t_queue *q);
void			enqueue(t_queue *q, t_list *node);
t_list			*dequeue(t_queue *q);
void			free_queue(t_queue *queue);

#endif
