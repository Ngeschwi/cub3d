/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:20:15 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/01 18:20:16 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char **str, char *buff)
{
	int		len_str;
	int		len_buff;
	int		i;
	char	*dst;

	i = -1;
	if (!(*str))
		return (ft_strdup(buff));
	len_str = ft_strlen(*str);
	len_buff = ft_strlen(buff);
	dst = malloc(sizeof(char) * (len_str + len_buff + 1));
	if (!dst)
		return (NULL);
	while (++i < len_str)
		dst[i] = (*str)[i];
	i = 0;
	while (i < len_buff)
	{
		dst[i + len_str] = buff[i];
		i++;
	}
	dst[i + len_str] = '\0';
	free(*str);
	return (dst);
}

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*str;
	int		nbr_read;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	str = NULL;
	nbr_read = read(fd, buff, BUFFER_SIZE);
	while (nbr_read > 0)
	{
		buff[nbr_read] = '\0';
		str = ft_strjoin(&str, buff);
		nbr_read = read(fd, buff, BUFFER_SIZE);
	}
	*line = ft_strdup(str);
	free(str);
	return (0);
}
