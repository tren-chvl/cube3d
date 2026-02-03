/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:45:08 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/03 16:11:33 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		floor_color;
	int		ceilling_color;
}	t_game;

typedef	struct s_map
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor[3];
	int		ceiling[3];
	char	**map;
	int	player_x;
	int	player_y;
	char	dir;
	char	*first_line;
}	t_map;

// free
void	free_split(char **tab);
void	free_map(t_map *map);
void	free_dup(char **m);

// parsing
int		parse_cub(t_map *map, char *file);
int		parse_elements(t_map *map, int fd);
int		parse_element_line(t_map *map, char *line);
int		parse_color(int dest[3], char *line);
int		parse_texture(char **dest, char *line);
int		parse_map(t_map *map, int fd);
char	**add_line(char **old, char *line, int count);
int		valide_map(t_map *map);
int		is_wall(t_map *map, int i, int j);
int		is_map_line(char *line);
void	init_game(t_map *map);
int		init_player(t_map *map, int i, int j);
int		check_player(t_map *map);
int		check_char(t_map *map);
char	**dup_map(t_map *map, int *h, int *w);
#endif
