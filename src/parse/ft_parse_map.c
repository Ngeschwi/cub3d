/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:19:08 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/08 12:06:46 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

static int	get_size_line(t_map *map, int idx_line)
{
	int	size;

	size = 0;
	while (map->line[idx_line] && map->line[idx_line] != '\n')
	{
		size++;
		idx_line++;
	}
	return (size);
}

static void	get_map(t_map *map)
{
	int	idx_line;
	int	idx_tab;
	int	idx_save;
	int	j;
	int	size;

	idx_line = 0;
	j = 0;
	while (map->line[idx_line])
	{
		idx_save = idx_line;
		size = get_size_line(map, idx_line);
		map->tab[j] = malloc(sizeof(char) * (size + 1));
		idx_tab = 0;
		idx_line = idx_save;
		while (map->line[idx_line] && map->line[idx_line] != '\n')
		{
			map->tab[j][idx_tab++] = map->line[idx_line];
			idx_line++;
		}
		map->tab[j][idx_tab] = '\0';
		idx_line++;
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
	map->first_line_of_map = 0;
	map->orientation_of_carac = 0;
	map->line = NULL;
	map->tab = NULL;
	map->nord_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_texture = NULL;
	map->ceil_texture = NULL;
	map->get_all_element = 0;
}

void	ft_parse_map(t_map *map, char *path_map)
{
	ft_init_map(map);
	get_nbr_line_of_map(map, path_map);
	get_map(map);
	get_element(map);
	check_element_in_map(map);
}
