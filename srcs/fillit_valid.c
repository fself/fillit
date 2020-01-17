/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_valid_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:12:06 by fself             #+#    #+#             */
/*   Updated: 2019/12/20 23:35:24 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fillit_push(char ***box, int i, int j, int number)
{
	int		q;

	q = 1;
	while (q < 4)
	{
		(*box)[i + g_tetrominos[number][q][0]][j +
			g_tetrominos[number][q][1]] = (*box)[i][j];
		q++;
	}
}

void	fillit_pop(char ***box, int i, int j, int number)
{
	int		q;

	q = 0;
	while (q < 4)
	{
		(*box)[i + g_tetrominos[number][q][0]][j +
			g_tetrominos[number][q][1]] = '.';
		q++;
	}
}

int		lets_try(char ***box, int size, int *tet, int step)
{
	int		i;
	int		j;
	int		co[2];

	if (step == tet[26])
		return (1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			co[0] = i;
			co[1] = j;
			if (put_tet_check(co, g_tetrominos[tet[step]], box, size))
			{
				(*box)[i][j] = 'A' + step;
				fillit_push(box, i, j, tet[step]);
				if (lets_try(box, size, tet, step + 1))
					return (1);
				fillit_pop(box, i, j, tet[step]);
			}
		}
	}
	return (0);
}

void	solve(int *tet)
{
	char	**box;
	int		size;
	int		i;
	int		j;

	size = 2;
	while (2 < 3)
	{
		box = (char**)malloc(sizeof(char*) * size);
		i = 0;
		while (i < size)
		{
			j = 0;
			box[i] = (char*)malloc(sizeof(char) * (size + 1));
			while (j < size)
				box[i][j++] = '.';
			box[i++][j] = 0;
		}
		if (lets_try(&box, size, tet, 0))
			break ;
		del_strstr(box, size++);
	}
	print_answer(box, size);
}

void	print_answer(char **box, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(box[i]);
		free(box[i++]);
		ft_putchar('\n');
	}
	free(box);
}
