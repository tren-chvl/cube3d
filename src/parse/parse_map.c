/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:35:32 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/09 02:30:26 by marcheva         ###   ########.fr       */
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

int	flood_dirs(char **m, t_vi t, int h, int w)
{
	t_vi	n;

	n.i = t.i + 1;
	n.j = t.j;
	if (!flood(m, n, h, w))
		return (0);
	n.i = t.i - 1;
	n.j = t.j;
	if (!flood(m, n, h, w))
		return (0);
	n.i = t.i;
	n.j = t.j + 1;
	if (!flood(m, n, h, w))
		return (0);
	n.i = t.i;
	n.j = t.j - 1;
	if (!flood(m, n, h, w))
		return (0);
	return (1);
}

int	flood(char **m, t_vi t, int h, int w)
{
	if (t.i < 0 || t.j < 0 || t.i >= h || t.j >= w)
		return (0);
	if (m[t.i][t.j] == '1')
		return (1);
	if (m[t.i][t.j] == ' ')
		return (0);
	if (m[t.i][t.j] == 'V')
		return (1);
	m[t.i][t.j] = 'V';
	return (flood_dirs(m, t, h, w));
}

void	fill_dup_map(char **dup, t_map *map, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		dup[i] = malloc(w + 1);
		j = 0;
		while (map->map[i][j])
		{
			dup[i][j] = map->map[i][j];
			j++;
		}
		while (j < w)
			dup[i][j++] = ' ';
		dup[i][j] = '\0';
		i++;
	}
}

char	**dup_map(t_map *map, int *h, int *w)
{
	char	**dup;
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
	fill_dup_map(dup, map, *h, *w);
	dup[*h] = NULL;
	return (dup);
}
