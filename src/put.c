/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:44:35 by bfiguet           #+#    #+#             */
/*   Updated: 2022/08/31 17:41:43 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_limits(t_game *game)
{
	if (!game->img_limit)
		ft_close_win(game);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->img_limit, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_put_floor(t_game *game)
{
	if (!game->img_floor)
		ft_close_win(game);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->img_floor, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_put_collect(t_game *game)
{
	if (!game->img_collect)
		ft_close_win(game);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->img_collect, game->pxl * game->x,
		game->pxl * game->y);
	game->obj_collect++;
}

void	ft_put_player(t_game *game)
{
	if (game->obj_collect == 0)
	{
		if (!game->img_winner)
			ft_close_win(game);
		game->play_y = game->y;
		game->play_x = game->x;
		mlx_put_image_to_window (game->mlx, game->mlx_win,
			game->img_winner, game->pxl * game->x,
			game->pxl * game->y);
	}
	else
	{
		if (!game->img_player)
			ft_close_win(game);
		game->play_y = game->y;
		game->play_x = game->x;
		mlx_put_image_to_window (game->mlx, game->mlx_win,
			game->img_player, game->pxl * game->x,
			game->pxl * game->y);
	}
}

void	ft_put_exit(t_game *game)
{
	if (game->obj_collect == 0)
	{
		if (!game->img_exit_open)
			ft_close_win(game);
		mlx_put_image_to_window (game->mlx, game->mlx_win,
			game->img_exit_open, game->pxl * game->x,
			game->pxl * game->y);
	}
	else
	{
		if (!game->img_exit_close)
			ft_close_win(game);
		mlx_put_image_to_window (game->mlx, game->mlx_win,
			game->img_exit_close, game->pxl * game->x,
			game->pxl * game->y);
	}	
}
