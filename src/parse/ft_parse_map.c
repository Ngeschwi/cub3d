/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:19:08 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/07 15:19:12 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

static int	get_size_line(t_map *map, int index_line)
{
	int	size;

	size = 0;
	while (map->line[index_line] && map->line[index_line] != '\n')
	{
		size++;
		index_line++;
	}
	return (size);
}

static void	get_map(t_map *map)
{
	int	index_line;
	int	index_tab;
	int	index_save;
	int	j;
	int	size;

	index_line = 0;
	j = 0;
	while (map->line[index_line])
	{
		index_save = index_line;
		size = get_size_line(map, index_line);
		map->tab[j] = malloc(sizeof(char) * (size + 1));
		index_tab = 0;
		index_line = index_save;
		while (map->line[index_line] && map->line[index_line] != '\n')
		{
			map->tab[j][index_tab++] = map->line[index_line];
			index_line++;
		}
		map->tab[j][index_tab] = '\0';
		index_line++;
		j++;
	}
	map->tab[j] = NULL;
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
		map->line = ft_strjoin(&map->line, line);
		map->line = ft_strjoin(&map->line, "\n");
		free(line);
		get = get_next_line(map->fd, &line);
	}
	map->nbr_line++;
	map->line = ft_strjoin(&map->line, line);
	map->line = ft_strjoin(&map->line, "\n");
	free(line);
	if (ft_strlen(map->line) <= 1)
		ft_error_exit("Error : The map is empty\n", map);
	map->tab = malloc(sizeof(char *) * (map->nbr_line + 1));
}

static void	ft_init_map(t_map *map)
{
	map->fd = 0;
	map->nbr_line = 0;
	map->line = NULL;
	map->tab = NULL;
	map->nord_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_texture = NULL;
	map->ceiling_texture = NULL;
	map->get_all_element = 0;
}

void	ft_parse_map(t_map *map, char *path_map)
{
	ft_init_map(map);
	get_nbr_line_of_map(map, path_map);
	get_map(map);
	get_element(map);
}
