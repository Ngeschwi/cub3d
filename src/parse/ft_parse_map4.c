/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:04 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/08 16:21:00 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_lenght_map(char **map)
{
	int	idx_tab;
	int	idx_line;
	int	lenght;

	lenght = 0;
	idx_tab = 0;
	while (map[idx_tab])
	{
		idx_line = 0;
		while (map[idx_tab][idx_line])
			idx_line++;
		if (idx_line > lenght)
			lenght = idx_line;
		idx_tab++;
	}
	return (lenght);
}

static char	**get_save_map(t_map *map, int size_malloc)
{
	int		idx_tab;
	int		idx_line;
	char	**save;
	
	idx_tab = 0;
	save = malloc(sizeof(char *) * (map->nbr_line + 1));
	if (!save)
		ft_error_exit("Error : malloc\n", map);
	while (map->tab[idx_tab])
	{
		idx_line = 0;
		save[idx_tab] = malloc(sizeof(char) * (size_malloc + 1));
		if (!save[idx_tab])
			ft_error_exit("Error : malloc\n", map);
		while (map->tab[idx_tab][idx_line])
		{
			save[idx_tab][idx_line] = map->tab[idx_tab][idx_line];
			idx_line++;
		}
		save[idx_tab][idx_line] = '\0';
		idx_tab++;
	}
	save[idx_tab] = NULL;
	return (save);
}

void	delete_element_to_keep_map(t_map *map)
{
	char	**save;
	int		i;
	int		idx_save;
	int		size_malloc;

	size_malloc = get_lenght_map(map->tab);
	save = get_save_map(map, size_malloc);
	idx_save = map->first_line_of_map;
	i = -1;
	while (map->tab[++i])
		free(map->tab[i]);
	free(map->tab);
	map->tab = malloc(sizeof(char *) * (map->nbr_line - idx_save + 1));
	i = 0;
	while (save[idx_save])
	{
		map->tab[i] = malloc(sizeof(char) * (size_malloc + 1));
		map->tab[i] = save[idx_save];
		map->tab[i][ft_strlen(save[idx_save])] = '\0';
		idx_save++;
		i++;
	}
	map->tab[i] = NULL;
}
