/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:24:48 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/03 16:05:15 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' )
		return (1);
	return (0);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_texture(char **dest, char *line)
{
	char	*path;

	if (*dest != NULL)
	{
		printf("Error\nDuplicate texture\n");
		return (0);
	}
	path = ft_strtrim(line, " \n");
	if (!path || path[0] == '\0')
	{
		printf("Error\nInvalid texture path\n");
		free(path);
		return (0);
	}
	*dest = path;
	return (1);
}

int	parse_color(int dest[3], char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	if (dest[0] != -1)
	{
		printf("Error\nDuplicate color\n");
		return (0);
	}
	split = ft_split(line, ',');
	if (!is_number(split[0]) || !is_number(split[1]) || !is_number(split[2]))
	{
		printf("Error\nInvalid color\n");
		free_split(split);
		return (0);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error\ncolor out of range\n");
		free_split(split);
		return (0);
	}
	dest[0] = r;
	dest[1] = g;
	dest[2] = b;
	free_split(split);
	return (1);
}

int	parse_element_line(t_map *map, char *line)
{
	char	*trim;
	int		ok;

	ok = 0;
	trim = ft_strtrim(line, " \t\n");
	if (!trim)
		return (0);
	if (!ft_strncmp(trim, "NO ", 3))
		ok = parse_texture(&map->north, trim + 3);
	else if (!ft_strncmp(trim, "SO ", 3))
		ok = parse_texture(&map->south, trim + 3);
	else if (!ft_strncmp(trim, "WE ", 3))
		ok = parse_texture(&map->west, trim + 3);
	else if (!ft_strncmp(trim, "EA ", 3))
		ok = parse_texture(&map->east, trim + 3);
	else if (!ft_strncmp(trim, "F ", 2))
		ok = parse_color(map->floor, trim + 2);
	else if (!ft_strncmp(trim, "C ", 2))
		ok = parse_color(map->ceiling, trim + 2);
	free(trim);
	return (ok);
}
