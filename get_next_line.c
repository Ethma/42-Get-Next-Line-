/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:28:27 by mabessir          #+#    #+#             */
/*   Updated: 2017/12/06 16:26:52 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			i;
	int			len;
	static char	*str;
	char		save;

	i = 0;
	if ((fd < 0 || (!str && !(str = ft_strnew(BUFF_SIZE)))))
		return (-1);
	while (ft_strchr(str, '\n') == NULL && i = read(fd, str, BUFF_SIZE) > 0)
	{
		len = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n'));
		*line = ft_strsub(str, 0, len);
		save = ft_strchr(str, '\n');
		i++;
	}
	return (i == 0 ? 0 : -1);
	return (1);
}