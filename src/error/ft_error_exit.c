/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:20:01 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/07 14:08:26 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	if (map->line != NULL)
		free(map->line);
	if (map->tab != NULL)
	{
		while (map->tab[i])
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
	}
}

void	ft_error_exit(char *error, t_map *map)
{
	printf("%s", error);
	ft_free(map);
	exit(0);
}
