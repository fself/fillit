/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_cheker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:10:16 by fself             #+#    #+#             */
/*   Updated: 2019/12/18 13:27:41 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_symbols(char **dest)
{
	int		j;
	int		k;
	int		n;

	n = 0;
	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (dest[j][k] != '#' && dest[j][k] != '.')
				return (0);
			if (dest[j][k] == '#')
				n++;
			k++;
		}
		j++;
	}
	if (n != 4)
		return (0);
	return (1);
}

int		check_coords(int k, int i, int j, char **dest)
{
	int		q;

	q = 0;
	while (q < 4)
	{
		if (i + g_tetrominos[k][q][0] >= 0 &&
				i + g_tetrominos[k][q][0] < 4 &&
				j + g_tetrominos[k][q][1] >= 0 &&
				j + g_tetrominos[k][q][1] < 4 &&
				dest[i + g_tetrominos[k][q][0]][j +
				g_tetrominos[k][q][1]] == '#')
			q++;
		else
			return (0);
	}
	return (1);
}

int		check_tetriminos(char **dest)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 19)
			{
				if (check_coords(k, i, j, dest))
				{
					del_strstr(dest, 4);
					return (k);
				}
			}
		}
	}
	del_strstr(dest, 4);
	return (-1);
}

int		ft_fillit_check(int fd, int step)
{
	char	*s;
	char	**buffer;
	int		i;

	buffer = (char**)malloc(sizeof(char*) * 4);
	i = 0;
	while (i < 5 && get_next_line(fd, &s) > 0)
	{
		if (i == 0 && ((ft_strlen(s) == 0 && step == 0) ||
					(ft_strlen(s) != 0 && step != 0)))
			return (-1);
		if (i == 0 && ft_strlen(s) != 0)
			i++;
		if (i == 0 && ft_strlen(s) == 0 && step != 0)
		{
			i++;
			continue;
		}
		if (i != 0 && ft_strlen(s) == 4)
			buffer[i++ - 1] = s;
		else
			return (-1);
	}
	return (return_value(i, buffer));
}

int		return_value(int i, char **buffer)
{
	if (i == 5 && check_symbols(buffer))
		return (check_tetriminos(buffer));
	del_strstr(buffer, i - 1);
	if (i == 0)
		return (-2);
	return (-1);
}
