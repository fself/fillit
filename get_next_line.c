/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrusty <jkrusty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:47:58 by jkrusty           #+#    #+#             */
/*   Updated: 2019/11/24 20:51:57 by jkrusty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_pushback(char const *dest, char const *src)
{
	char const	*new;

	new = ft_strjoin(dest, src);
	if (!new)
		return (0);
	free((void*)dest);
	return ((char*)new);
}

static void		ft_put_new_line(char **src, char **dst)
{
	char	*tmp;

	tmp = *src;
	if (ft_strchr(*src, '\n'))
	{
		*dst = ft_strsub(*src, 0, ft_strchr(*src, '\n') - *src);
		*src = ft_strdup(ft_strchr(*src, '\n') + 1);
	}
	else
	{
		*dst = ft_strdup(*src);
		*src = NULL;
	}
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char		*gnl[10240];
	char			buff[BUFF_SIZE + 1];
	int				n;

	if (fd < 0 || fd > 10240 || read(fd, NULL, 0) == -1
			|| line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = 0;
		if (!gnl[fd])
			gnl[fd] = ft_strnew(0);
		if (!(gnl[fd] = ft_pushback(gnl[fd], buff)))
			return (-1);
		if (ft_strchr(gnl[fd], '\n'))
			break ;
	}
	if (!gnl[fd] || !gnl[fd][0])
		return (0);
	ft_put_new_line(&gnl[fd], line);
	return (1);
}
