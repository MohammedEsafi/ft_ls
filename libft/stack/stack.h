/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:37:25 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/21 21:16:15 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

/*
 ** Definitions
*/

# define STACK_H

/*
 ** Includes
*/

# include "../libft.h"

/*
 ** Structures
*/

typedef struct	s_stack
{
	struct s_list	*head;
	unsigned int	size;
}				t_stack;

/*
 ** Stack Functions
*/

void			init_stack(t_stack *s);
void			push(t_stack *s, t_list *node);
t_list			*pop(t_stack *stack);
void			free_stack(t_stack *stack);

#endif
