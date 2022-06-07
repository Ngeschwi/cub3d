/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:35:38 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/06 09:37:29 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char **str, char *buff)
{
	int		len_str;
	int		len_buff;
	int		i;
	char	*dst;

	i = -1;
	if (*str == NULL)
		return (ft_strdup(buff));
	len_str = ft_strlen_gnl(*str);
	len_buff = ft_strlen_gnl(buff);
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
	ft_free_if_define(str);
	return (dst);
}
