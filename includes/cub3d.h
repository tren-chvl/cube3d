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
    void    *mlx;
    void    *win;
    char    **map;
    int     floor_color;
    int     ceiling_color;
    char    *tex_no;
    char    *tex_su;
    char    *tex_we;
    char    *tex_ea;
    double  player_x;
    double  player_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
}   t_game;

int     parse_cub(t_game *game, char *file);
int     init_mlx(t_game *game);
void    free_game(t_game *game);

#endif
