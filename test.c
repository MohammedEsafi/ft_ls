/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:44:30 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/05 20:49:23 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main()
{
	char buff[1025];
	bzero(buff,1025);
	readlink("lk2/",buff,1024);
	printf("%s\n",buff);
}