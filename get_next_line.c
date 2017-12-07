/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:28:27 by mabessir          #+#    #+#             */
/*   Updated: 2017/12/07 11:11:27 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			i;
	int			len;
	static char	*tmp;
	char		buff[BUFF_SIZE + 1];

	i = 0;
	if ((fd < 0 || !line || BUFF_SIZE <= 0))
		return (-1);
	if (!tmp)
		ft_strnew(BUFF_SIZE);
	while (i = read(fd, tmp, BUFF_SIZE) != 0 && ft_strchr(tmp, '\n') == NULL)
	{
		if (i == -1)
			return (-1);
		buff[i] = 0;
		tmp = ft_strjoin(tmp, buff, BUFF_SIZE); 
	}
	return (i == 0 ? 0 : 1);
}