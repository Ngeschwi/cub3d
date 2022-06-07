/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:19:08 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/07 13:27:00 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

static void	get_map(t_map *map)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (map->line[i])
	{
		while (map->line[i] != '\n')
		{
			size++;
			i++;
		}
		map->tab[j] = malloc(sizeof(char) * (i + 1));
		i = 0;
		while (map->line[i] != '\n')
		{
			map->tab[j][i] = map->line[i];
			i++;
		}
		i++;
		j++;
	}
	for(int x =0; map->tab[x]; x++)
		printf("%s\n", map->tab[x]);
}

static void	get_nbr_line_of_map(t_map *map, char *path_map)
{
	char	*line;
	int		get;

	line = NULL;
	map->fd = open(path_map, O_RDONLY);
	if (map->fd == -1)
		ft_error_exit("Error : The path doesn't match", map);
	get = get_next_line(map->fd, &line);
	while (get > 0)
	{
		map->nbr_line++;
		map->line = ft_strdup(line);
		free(line);
		get = get_next_line(map->fd, &line);
	}
	map->nbr_line++;
	map->line = ft_strdup(line);
	free(line);
	map->tab = malloc(sizeof(char *) * (map->nbr_line + 1));
}

static void	ft_init_map(t_map *map)
{
	map->fd = 0;
	map->nbr_line = 0;
	map->tab = NULL;
	map->nord_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_texture = NULL;
	map->ceiling_texture = NULL;
}

void	ft_parse_map(char *path_map)
{
	t_map	map;

	ft_init_map(&map);
	get_nbr_line_of_map(&map, path_map);
	get_map(&map);
}
