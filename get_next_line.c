/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:28:27 by mabessir          #+#    #+#             */
/*   Updated: 2017/12/10 21:58:08 by Mendy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	test(int fd, char **tmp)
{
	char	*buff;
	char	*str;
	int		i;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
			return (-1);
		i = read(fd, buff, BUFF_SIZE);
		if (i > 0)
		{
			buff[i] = '\0';
			str = ft_strjoin(*tmp, buff);
			free(*tmp);
			*tmp = str;
		}
		free(buff);
		return (i);
}

int			get_next_line(const int fd, char **line)
{
	int			i;
	static char	*tmp;
	char		*buff;

	if ((!tmp && (tmp = (char *)malloc(sizeof(tmp))) == NULL) || fd < 0 ||
	!line || BUFF_SIZE <= 0)
		return (-1);
	buff = ft_strchr(tmp, '\n');
	while (!buff)
	{
		i = test(fd, &tmp);
		if (i < 0)
			return (-1);
		if (!i)
		{
			if (!ft_strlen(tmp))
				return (0);
			tmp = ft_strjoin(tmp, "\n");
		}
		buff = ft_strchr(tmp, '\n');
	}
	*line = ft_strsub(tmp, 0, ft_strlen(tmp) - ft_strlen(buff));
	tmp = ft_strdup(buff + 1);
	return (1);
}
