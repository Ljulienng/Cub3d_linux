/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:27:19 by jnguyen           #+#    #+#             */
/*   Updated: 2020/01/29 13:06:12 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

int		gnl_return(char **str, char **line, int fd, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
	{
		*line = ft_strnew(0);
		return (0);
	}
	return (get_new_line(str, line, fd, ret));
}

int		get_new_line(char **str, char **line, int fd, int ret)
{
	char	*cur;
	int		len;

	len = 0;
	while (str[fd][len] != '\0' && str[fd][len] != '\n')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_substr(str[fd], 0, len);
		cur = ft_strdup(len + 1 + str[fd]);
		ft_strdel(&str[fd]);
		str[fd] = cur;
		if (*str[fd] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*str[1024];
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;

	if (!line || fd < 0 || BUFFER_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str[fd];
		if (!(str[fd] = ft_strjoin(str[fd], buff)))
			str[fd] = ft_strnew(0);
		ft_strdel(&tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (gnl_return(str, line, fd, ret));
}
