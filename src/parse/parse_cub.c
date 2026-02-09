/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:01:57 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/05 15:39:21 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_map_start(t_map *map, char *line)
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
			return (handle_map_start(map, line));
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

char	**read_map_loop(char **tmp, int *count, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' && *count == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		tmp = add_line(tmp, line, *count);
		if (!tmp)
		{
			printf("Error\nmalloc failed\n");
			free(line);
			return (NULL);
		}
		(*count)++;
		free(line);
		line = get_next_line(fd);
	}
	return (tmp);
}

int	parse_map(t_map *map, int fd)
{
	char	**tmp;
	int		count;

	tmp = NULL;
	count = 0;
	if (map->first_line)
	{
		tmp = add_line(tmp, map->first_line, count++);
		free(map->first_line);
		map->first_line = NULL;
	}
	tmp = read_map_loop(tmp, &count, fd);
	if (!tmp)
		return (0);
	map->map = tmp;
	return (valide_map(map));
}
