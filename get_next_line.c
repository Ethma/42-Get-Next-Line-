/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:28:27 by mabessir          #+#    #+#             */
/*   Updated: 2017/12/08 16:04:15 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			i;
	static char	*tmp;
	char		buff[BUFF_SIZE + 1];

	i = 1;
	if ((fd < 0 || !line || BUFF_SIZE <= 0))
		return (-1);
	if (!tmp)
		ft_strnew(0);
	while ((i = read(fd, tmp, BUFF_SIZE)) != 0 && (ft_strchr(tmp, '\n')
	== NULL))
	{
		if (i == -1)
			return (-1);
		buff[i] = 0;
		tmp = ft_strjoin(tmp, buff);
	}
	if (ft_strchr(tmp, '\n') || ((*line = ft_strdup(tmp)) && 0))
		*line = ft_strsub(tmp, 0, ft_strchr(tmp, '\n') - tmp + 1);
	if (i != 0)
		line[0][ft_strlen(*line) - 1] = 0;
	tmp = ft_strsub(tmp, ft_strchr(tmp, '\n') - tmp + 1,
	ft_strlen(ft_strchr(tmp, '\n')));
	return (i == 0 ? 0 : 1);
}
