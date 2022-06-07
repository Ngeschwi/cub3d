/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:56:57 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/07 13:21:20 by ngeschwi         ###   ########.fr       */
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
# include "mlx.h"
# include "get_next_line.h"

typedef struct	s_map
{
	int		fd;
	int		nbr_line;
	char	*line;
	char	**tab;
	char	*nord_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_texture;
	char	*ceiling_texture;
}				t_map;

void	ft_putstr(char *str);
char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);

void	ft_error_exit(char *error, t_map *map);

void	ft_parse_map(char *path_map);

#endif