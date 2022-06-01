/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:19:08 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/01 18:30:40 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	ft_parse_map(char *path_map)
{
	t_map	map;
	char	*line;

	map.fd = open(path_map, O_RDONLY);
	if (map.fd == -1)
		ft_error_exit("Error : The path doesn't match");
	get_next_line(map.fd, &line);
	map.line = ft_strdup(line);
	free(line);
	if (ft_strlen(map.line) == 0)
		ft_error_exit("Error : The map is empty");
	printf("%s\n", map.line);
}
