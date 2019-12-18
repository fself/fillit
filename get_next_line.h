/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrusty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:50:32 by jkrusty           #+#    #+#             */
/*   Updated: 2019/12/18 13:26:07 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 16
# include <stdio.h>
# include <fcntl.h>

static const int	g_tetrominos[19][4][2] = {
	{{0, 0}, {1, 1}, {1, 0}, {0, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {1, 0}, {1, -1}, {1, -2}},
	{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{0, 0}, {1, 0}, {0, 1}, {0, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
	{{0, 0}, {0, 1}, {1, 0}, {2, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	{{0, 0}, {1, 0}, {1, -1}, {0, 1}},
	{{0, 0}, {1, 0}, {1, -1}, {2, -1}},
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}, {1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, -1}}};
void				print_answer(char **box, int size);
int					return_value(int i, char **buffer);
int					put_tet_check(const int co[2], const int coords[4][2],
		char ***box, int size);
int					get_next_line(const int fd, char **line);
void				del_strstr(char **dest, int len);
int					check_symbols(char **dest);
int					check_coords(int k, int i, int j, char **dest);
int					check_tetriminos(char **dest);
void				fillit_push(char ***box, int i, int j, int number);
void				fillit_pop(char ***box, int i, int j, int number);
int					lets_try(char ***box, int size, int *tet, int step);
void				solve(int *tet);
int					ft_fillit_check(int fd, int step);

#endif
