/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:08:22 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/09 02:30:33 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valide_map(t_map *map)
{
	if (!check_char(map))
		return (0);
	if (!check_player(map))
		return (0);
	if (!check_closed(map))
		return (0);
	return (1);
}

int	check_char(t_map *map)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			tmp = map->map[i][j];
			if (tmp != '0' && tmp != '1' && tmp != 'N' && tmp != 'S'
				&& tmp != 'E' && tmp != 'W')
			{
				printf("Error\nInvalid character in map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				if (!init_player(map, i, j))
					return (0);
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (printf("Errror\nInvalid number of player\n"), 0);
	return (1);
}

int	check_all_cells(char **dup, int h, int w)
{
	t_vi	t;

	t.i = 0;
	while (t.i < h)
	{
		t.j = 0;
		while (t.j < w)
		{
			if (dup[t.i][t.j] == '0' || dup[t.i][t.j] == 'N'
				|| dup[t.i][t.j] == 'S' || dup[t.i][t.j] == 'E'
				|| dup[t.i][t.j] == 'W')
			{
				if (!flood(dup, t, h, w))
				{
					printf("Error\nMap is not closed\n");
					return (0);
				}
			}
			t.j++;
		}
		t.i++;
	}
	return (1);
}

int	check_closed(t_map *map)
{
	char	**dup;
	int		h;
	int		w;

	dup = dup_map(map, &h, &w);
	if (!dup)
		return (0);
	if (!check_all_cells(dup, h, w))
	{
		free_dup(dup);
		return (0);
	}
	free_dup(dup);
	return (1);
}
