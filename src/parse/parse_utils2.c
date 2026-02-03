/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:31:43 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/03 16:13:51 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_map *map, int i, int j)
{
	map->player_x = i;
	map->player_y = j;
	map->dir = map->map[i][j];
	map->map[i][j] = '0';
	return (1);
}
