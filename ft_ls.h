/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:14:03 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/06 15:33:20 by mesafi           ###   ########.fr       */
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
# define FLAG_F 32U
# define FLAG_G 64U
# define FLAG_D 128U
# define FLAG_1 256U
# define COLOR 512U

# define OPTS "lRGratfgd1"

# define RESET "\033[0m"
/*
 ** Includes
*/

# include "libft/libft.h"
# include "libft/stack/stack.h"
# include "libft/array_list/array_list.h"
# include <dirent.h>
// # include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>
# include <sys/types.h>
# include <unistd.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <time.h>

/*
 ** Structures
*/

typedef struct	s_datum
{
	char			*filename;
	char			*path;
	struct stat		stat;
}				t_datum;

typedef struct	s_listdir
{
	char			*parent;
	unsigned int	*options;
	size_t			*max_lenght;
	t_array_list	book;
}				t_listdir;

typedef struct	s_col
{
	int 		x;
	int			y;
	int			index;
	int			last_index;
	int			*max_row_col;
	int			tmp;
	int			tmp1;
}				t_col;


/*
 ** ft_ls Functions
*/

int				ft_options(unsigned int *options, char **argv, int len);
void			ft_get_list(char **argv, int argc, int mark, t_listdir *listdir);
void			ft_merge_sort(t_listdir *listdir, int left, int right);
void			ft_reader(t_listdir *listdir, int bulb);
void			free_list_dir(t_listdir *listdir);
int				ft_print_flag_list(t_listdir *listdir, size_t *max_lenght,
					int i, char *color);
size_t			*find_max_lenght(t_listdir *listdir, int bulb);
char			*ft_join_path(char *parent, char *child);
int				ft_print_flag_non_list(int x, int y, t_listdir *listdir, int i);
int				*ft_get_parameter(t_listdir *listdir);
int				cursor_first_pos(void);

#endif
