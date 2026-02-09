/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:24:48 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/05 15:39:56 by marcheva         ###   ########.fr       */
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

int	fill_and_check_rgb(t_va *t, char **split)
{
	t->r_str = ft_strtrim(split[0], " \t");
	t->g_str = ft_strtrim(split[1], " \t");
	t->b_str = ft_strtrim(split[2], " \t");
	if (!is_number(t->r_str) || !is_number(t->g_str) || !is_number(t->b_str))
	{
		printf("Error\nInvalid color\n");
		free(t->r_str);
		free(t->g_str);
		free(t->b_str);
		return (0);
	}
	t->r = ft_atoi(t->r_str);
	t->g = ft_atoi(t->g_str);
	t->b = ft_atoi(t->b_str);
	free(t->r_str);
	free(t->g_str);
	free(t->b_str);
	if (t->r < 0 || t->r > 255 || t->g < 0 || t->g > 255
		|| t->b < 0 || t->b > 255)
	{
		printf("Error\ncolor out of range\n");
		return (0);
	}
	return (1);
}

int	parse_color(int dest[3], char *line)
{
	char	**split;
	t_va	t;

	if (dest[0] != -1)
	{
		printf("Error\nDuplicate color\n");
		return (0);
	}
	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		printf("Error\nInvalid color\n");
		free_split(split);
		return (0);
	}
	if (!fill_and_check_rgb(&t, split))
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	dest[0] = t.r;
	dest[1] = t.g;
	dest[2] = t.b;
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
