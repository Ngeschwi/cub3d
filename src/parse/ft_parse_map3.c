/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:19:28 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/08 15:33:52 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_line_around_zero(t_map *map, int idx_tab, int idx_line)
{
	int	i;
	int	size_line;

	i = 0;
	while (i < 3)
	{
		size_line = ft_strlen(map->tab[idx_tab]);
		if (idx_line >= size_line || map->tab[idx_tab][idx_line] == ' ')
			ft_error_exit("Error : invalid map : the map is open\n", map);
		i++;
		idx_line++;
	}
}

static void	check_if_map_is_close(t_map *map)
{
	int	idx_tab;
	int	idx_line;

	idx_tab = map->first_line_of_map;
	while (map->tab[idx_tab])
	{
		idx_line = 0;
		while (map->tab[idx_tab][idx_line])
		{
			if (map->tab[idx_tab][idx_line] == '0')
			{
				if (idx_line == 0)
					ft_error_exit("Error : invalid map : the map is open\n", map);
				check_line_around_zero(map, idx_tab - 1, idx_line - 1);
				check_line_around_zero(map, idx_tab, idx_line - 1);
				check_line_around_zero(map, idx_tab + 1, idx_line - 1);
			}
			idx_line++;
		}
		idx_tab++;
	}
}

static void	is_good_carac(t_map *map, int idx_tab, int idx_line)
{
	if (map->tab[idx_tab][idx_line] != ' ' && map->tab[idx_tab][idx_line] != '1'
		&& map->tab[idx_tab][idx_line] != '0'
		&& map->tab[idx_tab][idx_line] != 'N'
		&& map->tab[idx_tab][idx_line] != 'S'
		&& map->tab[idx_tab][idx_line] != 'E'
		&& map->tab[idx_tab][idx_line] != 'W')
		ft_error_exit("Error : wrong caractere in map\n", map);
	if (map->tab[idx_tab][idx_line] != ' ' && map->tab[idx_tab][idx_line] != '1'
		&& map->tab[idx_tab][idx_line] != '0')
	{
		if (map->orientation_of_carac != 0)
			ft_error_exit("Error : more than one position\n", map);
		else
		{
			map->orientation_of_carac = map->tab[idx_tab][idx_line];
			map->carac_x = idx_line;
			map->carac_y = idx_tab;
		}
	}
}

void	check_element_in_map(t_map *map)
{
	int	idx_tab;
	int	idx_line;

	idx_tab = map->first_line_of_map;
	while (map->tab[idx_tab])
	{
		idx_line = 0;
		while (map->tab[idx_tab][idx_line])
		{
			is_good_carac(map, idx_tab, idx_line);
			idx_line++;
		}
		idx_tab++;
	}
	check_if_map_is_close(map);
}
