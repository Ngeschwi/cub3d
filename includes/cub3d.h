/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:56:57 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/01 18:29:20 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibX/mlx.h"

typedef struct	s_map
{
	int		fd;
	char	*line;
}				t_map;

int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);

void	ft_error_exit(char *error);

void	ft_parse_map(char *path_map);

#endif