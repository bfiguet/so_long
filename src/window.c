/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:37:06 by bfiguet           #+#    #+#             */
/*   Updated: 2022/08/31 17:43:20 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_game *game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_free(game);
		exit(0);
	}
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * (game->map_y + 1), "so_long by bfiguet");
	if (!game->mlx_win)
	{
		ft_free(game);
		free(game->mlx);
		exit(0);
	}
	ft_init_img_ptr(game);
	ft_fill_win(game);
}

void	ft_destroy_all_img(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_limit)
		mlx_destroy_image(game->mlx, game->img_limit);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_winner)
		mlx_destroy_image(game->mlx, game->img_winner);
	if (game->img_exit_open)
		mlx_destroy_image(game->mlx, game->img_exit_open);
	if (game->img_exit_close)
		mlx_destroy_image(game->mlx, game->img_exit_close);
}

int	ft_close_win(t_game *game)
{
	ft_destroy_all_img(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	ft_free(game);
	free(game->mlx);
	exit(1);
	return (0);
}

int	ft_total_collect(t_game *game)
{
	int	i;

	i = 0;
	game->y = 0;
	while (game->y < game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			if (game->map[game->y][game->x] == 'C')
				i++;
			game->x++;
		}
		game->y++;
	}
	return (i);
}

void	ft_fill_win(t_game *game)
{
	game->obj_collect = ft_total_collect(game);
	game->y = 0;
	while (game->y <= game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			if (game->map[game->y][game->x] == '0')
				ft_put_floor(game);
			else if (game->map[game->y][game->x] == '1')
				ft_put_limits(game);
			else if (game->map[game->y][game->x] == 'C')
				ft_put_collect(game);
			else if (game->map[game->y][game->x] == 'P')
				ft_put_player(game);
			else if (game->map[game->y][game->x] == 'E')
				ft_put_exit(game);
			game->x++;
		}
		game->y++;
	}
	ft_printf("shifting: %d\n", game->play_move);
}
