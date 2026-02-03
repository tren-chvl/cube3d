/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:54:17 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/03 16:13:31 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	free(tab[i]);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->east)
		free(map->east);
	if (map->west)
		free(map->west);
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	free_dup(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}
