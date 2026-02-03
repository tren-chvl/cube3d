/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:01:57 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/03 16:07:56 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_elements_parsed(t_map *map)
{
	return (map->north && map->south && map->east && map->west);
}

int	parse_elements(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (is_map_line(line))
		{
			if (!all_elements_parsed(map))
			{
				printf("Error\nMissing elements before map\n");
				free(line);
				return (0);
			}
			map->first_line = ft_strdup(line);
			free(line);
			return (1);
		}
		if (!parse_element_line(map, line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	printf("Error\nMissing map\n");
	return (0);
}

int	parse_cub(t_map *map, char *file)
{
	int	fd;

	init_game(map);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\ncannot open file\n");
		return (0);
	}
	if (!parse_elements(map, fd))
	{
		close(fd);
		return (0);
	}
	if (!parse_map(map, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	parse_map(t_map *map, int fd)
{
	char	*line;
	int		count;
	char	**tmp;

	tmp = NULL;
	count = 0;
	if (map->first_line)
	{
		tmp = add_line(tmp, map->first_line, count++);
		free(map->first_line);
		map->first_line = NULL;
	}
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' && count == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		tmp = add_line(tmp, line, count);
		if (!tmp)
		{
			printf("Error\nmalloc failed\n");
			return (0);
		}
		count++;
		free(line);
		line = get_next_line(fd);
	}
	map->map = tmp;
	return (valide_map(map));
}

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