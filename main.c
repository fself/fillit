/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:39:33 by fself             #+#    #+#             */
/*   Updated: 2019/12/18 13:20:38 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		put_tet_check(const int co[2], const int coords[4][2],
		char ***box, int size)
{
	int		count;
	int		k;

	count = 0;
	k = 0;
	while (k < 4)
	{
		if (co[0] + coords[k][0] >= 0 && co[0] + coords[k][0] < size &&
				co[1] + coords[k][1] >= 0 && co[1] + coords[k][1] < size &&
				(*box)[co[0] + coords[k][0]][co[1] + coords[k][1]] == '.')
			count++;
		k++;
	}
	if (count == 4)
		return (1);
	return (0);
}

void	del_strstr(char **dest, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

int		main(int argc, char **argv)
{
	int		tetris[27];
	int		check;
	int		len;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	len = 0;
	check = ft_fillit_check(fd, 0);
	while (check >= 0)
	{
		tetris[len++] = check;
		check = ft_fillit_check(fd, len);
	}
	tetris[26] = len;
	if (check == -2 && len >= 1 && len <= 26)
		solve(tetris);
	else
		ft_putstr("error\n");
	return (0);
}
