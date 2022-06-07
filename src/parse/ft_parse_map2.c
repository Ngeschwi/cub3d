/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:57:20 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/07 15:25:22 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	stock_path_element(t_map *map, char **texture, int idx_tab, int idx_line)
{
	int	size_texture;
	int	idx_texture;
	int	idx_save;

	size_texture = 0;
	idx_texture = 0;
	while (map->tab[idx_tab][idx_line] == ' ')
		idx_line++;
	idx_save = idx_line;
	while (map->tab[idx_tab][idx_line] && map->tab[idx_tab][idx_line] != ' ')
	{
		size_texture++;
		idx_line++;
	}
	idx_line = idx_save;
	*texture = malloc(sizeof(char) * (size_texture + 1));
	if (!*texture)
		ft_error_exit("Error : malloc initialisation\n", map);
	printf("%d\n", size_texture);
	while (map->tab[idx_tab][idx_line] && map->tab[idx_tab][idx_line] != ' ')
	{
		printf("%d et %d\n", idx_texture, idx_line);
		printf("%c\n", map->tab[idx_tab][idx_line]);
		*texture[idx_texture] = map->tab[idx_tab][idx_line];
		idx_texture++;
		idx_line++;
	}
	*(texture[idx_texture]) = '\0';
}

static void	check_which_element(t_map *map, int idx_tab, int idx_line)
{
	if (map->tab[idx_tab][idx_line + 1])
	{
		if (map->tab[idx_tab][idx_line] == 'N' && map->tab[idx_tab][idx_line + 1] == 'O')
			stock_path_element(map, &map->nord_texture, idx_tab, idx_line + 2);
		else if (map->tab[idx_tab][idx_line] == 'S' && map->tab[idx_tab][idx_line + 1] == 'O')
			stock_path_element(map, &map->south_texture, idx_tab, idx_line + 2);
		else if (map->tab[idx_tab][idx_line] == 'W' && map->tab[idx_tab][idx_line + 1] == 'E')
			stock_path_element(map, &map->west_texture, idx_tab, idx_line + 2);
		else if (map->tab[idx_tab][idx_line] == 'E' && map->tab[idx_tab][idx_line + 1] == 'A')
			stock_path_element(map, &map->east_texture, idx_tab, idx_line + 2);
		else if (map->tab[idx_tab][idx_line] == 'F')
			stock_path_element(map, &map->floor_texture, idx_tab, idx_line + 1);
		else if (map->tab[idx_tab][idx_line] == 'C')
			stock_path_element(map, &map->ceiling_texture, idx_tab, idx_line + 1);
		else
			ft_error_exit("Error : texture's map invalid\n", map);
		map->get_all_element++;
	}
}

void	get_element(t_map *map)
{
	int	idx_tab;
	int	idx_line;

	idx_tab = 0;
	idx_line = 0;
	while (map->tab[idx_tab])
	{
		while (map->tab[idx_tab][idx_line] && map->tab[idx_tab][idx_line] == ' ')
			idx_line++;
		if (map->tab[idx_tab][idx_line] == '\0')
		{
			idx_line = 0;
			idx_tab++;
		}
		else
			check_which_element(map, idx_tab, idx_line);
		if (map->get_all_element == 5)
			break;
		idx_tab++;
	}
	if (map->get_all_element < 5)
		ft_error_exit("Error : there aren't all element in the map file\n", map);
	// printf("%s\n", map->nord_texture);
	// printf("%s\n", map->south_texture);
	// printf("%s\n", map->west_texture);
	// printf("%s\n", map->east_texture);
	// printf("%s\n", map->ceiling_texture);
	// printf("%s\n", map->floor_texture);
}
