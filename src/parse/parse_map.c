/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:35:32 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/03 16:11:10 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**add_line(char **old, char *line, int count)
{
	char	**new;
	int		i;
	int		len;

	new = malloc(sizeof(char *) * (count + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = old[i];
		i++;
	}
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	new[count] = malloc(len + 1);
	ft_memcpy(new[count], line, len);
	new[count][len] = '\0';
	new[count + 1] = NULL;
	free(old);
	return (new);
}

int	flood(char **m, int x, int y, int h, int w)
{
	if (x < 0 || y < 0 || x >= h || y >= w)
		return (0);
	if (m[x][y] == '1')
		return (1);
	if (m[x][y] == ' ')
		return (0);
	if (m[x][y] == 'V')
		return (1);
	m[x][y] = 'V';
	if (!flood(m, x + 1, y, h, w))
		return (0);
	if (!flood(m, x - 1, y, h, w))
		return (0);
	if (!flood(m, x, y + 1, h, w))
		return (0);
	if (!flood(m, x, y - 1, h, w))
		return (0);
	return (1);
}

char	**dup_map(t_map *map, int *h, int *w)
{
	char	**dup;
	int		i;
	int		j;
	int		len;

	*h = 0;
	*w = 0;
	while (map->map[*h])
	{
		len = ft_strlen(map->map[*h]);
		if (len > *w)
			*w = len;
		(*h)++;
	}
	dup = malloc(sizeof(char *) * (*h + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < *h)
	{
		dup[i] = malloc(*w + 1);
		j = 0;
		while (map->map[i][j])
		{
			dup[i][j] = map->map[i][j];
			j++;
		}
		while (j < *w)
			dup[i][j++] = ' ';
		dup[i][j] = '\0';
	}
	dup[*h] = NULL;
	return (dup);
}
