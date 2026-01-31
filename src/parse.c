#include "../includes/cub3d.h"


int parse_club(t_game *game, char *file)
{
    int fd;

    init_game(game);
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\ncannot open file\n");
        return (0);
    }
    if (!parse_elements(game, fd))
    {
        close(fd);
        return (0);
    }
    if (!parse_map(game, fd))
    {
        close(fd);
        return (0);
    }
    close(fd);
    return (1);
}