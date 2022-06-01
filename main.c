/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:19:13 by ngeschwi          #+#    #+#             */
/*   Updated: 2022/06/01 18:19:14 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error Argument");
		return (EXIT_FAILURE);
	}
	else
	{
		ft_parse_map(argv[1]);
	}
	return (EXIT_SUCCESS);
}
