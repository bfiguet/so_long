/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:08:21 by bfiguet           #+#    #+#             */
/*   Updated: 2022/08/31 17:47:42 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_init_buff(char **av)
{
	int		fd;
	char	*line;
	char	*buff;

	buff = malloc(sizeof(char *) + 1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		free(buff);
		ft_printf("Error\nCan't read map\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		buff = ft_strjoin(buff, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (buff);
}

void	ft_init_struct(t_game *game)
{
	game->map_x = 0;
	game->map_y = 0;
	game->map_area = 0;
	game->x = 0;
	game->y = 0;
	game->pxl = 0;
	game->player = 0;
	game->play_move = 0;
	game->obj_collect = 0;
	game->exit = 0;
}

void	ft_init_img_ptr(t_game *game)
{
	game->img_limit = mlx_xpm_file_to_image(game->mlx,
			"./img/limit.xpm", &game->pxl, &game->pxl);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./img/floor.xpm", &game->pxl, &game->pxl);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"./img/collect.xpm", &game->pxl, &game->pxl);
	game->img_winner = mlx_xpm_file_to_image(game->mlx,
			"./img/winner.xpm", &game->pxl, &game->pxl);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./img/player.xpm", &game->pxl, &game->pxl);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"./img/exit_open.xpm", &game->pxl, &game->pxl);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx,
			"./img/exit_close.xpm", &game->pxl, &game->pxl);
}
