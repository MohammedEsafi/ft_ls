/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:14:03 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/02 11:20:56 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

/*
 ** Definitions
*/

# define FT_LS_H

# define TRUE 1
# define FALSE 0

# define LIST 1U
# define REVERSE 2U
# define ALL 4U
# define RECURSIVE 8U
# define TIME 16U

# define OPTS "lRrat"

/*
 ** Includes
*/

# include "libft/libft.h"
# include "libft/stack/stack.h"
# include "libft/array_list/array_list.h"
# include <dirent.h>
// # include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
// # include <time.h>

/*
 ** Structures
*/

typedef struct	s_datum
{
	char			*filename;
	struct stat		stat;
}				t_datum;

typedef struct	s_listdir
{
	char			*parent;
	unsigned int	*options;
	t_array_list	book;
}				t_listdir;

/*
 ** ft_ls Functions
*/

int				ft_options(unsigned int *options, char **argv, int len);
void			ft_get_list(char **argv, int argc, int mark, t_listdir *listdir);
void			ft_merge_sort(t_listdir *listdir, int left, int right);
void			ft_reader(t_listdir *listdir, int bulb);

#endif
