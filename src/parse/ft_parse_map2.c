/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:57:20 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/08 15:33:52 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_first_line_of_map(t_map *map, int idx_tab)
{
	int	idx_line;

	while (map->tab[idx_tab])
	{
		idx_line = 0;
		while (map->tab[idx_tab][idx_line]
			&& map->tab[idx_tab][idx_line] == ' ')
			idx_line++;
		if (map->tab[idx_tab][idx_line] != '\0')
		{
			map->first_line_of_map = idx_tab;
			return ;
		}
		idx_tab++;
	}
}

static char	*stock_path_element(t_map *map, int idx_tab, int idx_line)
{
	int		size_texture;
	int		idx_texture;
	int		idx_save;
	char	*texture;

	size_texture = 0;
	idx_texture = 0;
	while (map->tab[idx_tab][idx_line] == ' ')
		idx_line++;
	idx_save = idx_line;
	while (map->tab[idx_tab][idx_line++])
		size_texture++;
	idx_line = idx_save;
	texture = malloc(sizeof(char) * (size_texture + 1));
	if (!texture)
		ft_error_exit("Error : malloc initialisation\n", map);
	while (map->tab[idx_tab][idx_line])
	{
		texture[idx_texture] = map->tab[idx_tab][idx_line];
		idx_texture++;
		idx_line++;
	}
	texture[idx_texture] = '\0';
	return (texture);
}

static void	check_which_element(t_map *map, int idx_tab, int idx_line)
{
	if (map->tab[idx_tab][idx_line + 1])
	{
		if (map->tab[idx_tab][idx_line] == 'N'
			&& map->tab[idx_tab][idx_line + 1] == 'O')
			map->nord_texture = stock_path_element(map, idx_tab, idx_line + 2);
		else if (map->tab[idx_tab][idx_line] == 'S'
			&& map->tab[idx_tab][idx_line + 1] == 'O')
			map->south_texture = stock_path_element(map, idx_tab, idx_line + 2);
		else if (map->tab[idx_tab][idx_line] == 'W'
			&& map->tab[idx_tab][idx_line + 1] == 'E')
			map->west_texture = stock_path_element(map, idx_tab, idx_line + 2);
		else if (map->tab[idx_tab][idx_line] == 'E'
			&& map->tab[idx_tab][idx_line + 1] == 'A')
			map->east_texture = stock_path_element(map, idx_tab, idx_line + 2);
		else if (map->tab[idx_tab][idx_line] == 'F')
			map->floor_texture = stock_path_element(map, idx_tab, idx_line + 1);
		else if (map->tab[idx_tab][idx_line] == 'C')
			map->ceil_texture = stock_path_element(map, idx_tab, idx_line + 1);
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
	while (map->tab[idx_tab])
	{
		idx_line = 0;
		while (map->tab[idx_tab][idx_line]
			&& map->tab[idx_tab][idx_line] == ' ')
			idx_line++;
		if (map->tab[idx_tab][idx_line] != '\0')
			check_which_element(map, idx_tab, idx_line);
		idx_tab++;
		if (map->get_all_element == 6)
			break ;
	}
	if (map->get_all_element < 6)
		ft_error_exit("Error : there aren't all element in the map file\n", map);
	get_first_line_of_map(map, idx_tab);
}
