/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:41:48 by bfiguet           #+#    #+#             */
/*   Updated: 2022/08/31 14:49:41 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	game->map[game->play_y - 1][game->play_x] = 'P';
	game->map[game->play_y][game->play_x] = '0';
	game->play_move++;
	ft_fill_win(game);
}

void	ft_move_down(t_game *game)
{
	game->map[game->play_y + 1][game->play_x] = 'P';
	game->map[game->play_y][game->play_x] = '0';
	game->play_move++;
	ft_fill_win(game);
}

void	ft_move_left(t_game *game)
{
	game->map[game->play_y][game->play_x - 1] = 'P';
	game->map[game->play_y][game->play_x] = '0';
	game->play_move++;
	ft_fill_win(game);
}

void	ft_move_right(t_game *game)
{
	game->map[game->play_y][game->play_x + 1] = 'P';
	game->map[game->play_y][game->play_x] = '0';
	game->play_move++;
	ft_fill_win(game);
}
/*
ESC = 53 / 65307
D = 2 / 100
S = 1 / 115
A = 0 / 97
W = 13 / 119
0 = emplacement vide
1 = mur
C = collect
E = exit
P = player
*/

int	ft_key(int keyhook, t_game *game)
{
	if (keyhook == 65307)
		ft_close_win(game);
	else if (game->obj_collect == 0
		&& ((keyhook == 100 && game->map[game->play_y][game->play_x + 1] == 'E')
		|| (keyhook == 115 && game->map[game->play_y + 1][game->play_x] == 'E')
		|| (keyhook == 97 && game->map[game->play_y][game->play_x - 1] == 'E')
		|| (keyhook == 119
		&& game->map[game->play_y - 1][game->play_x] == 'E')))
	{
		ft_printf("Perfect!\n");
		ft_close_win(game);
	}
	else if (keyhook == 119 && game->map[game->play_y - 1][game->play_x] != '1'
			&& game->map[game->play_y - 1][game->play_x] != 'E')
		ft_move_up(game);
	else if (keyhook == 97 && game->map[game->play_y][game->play_x - 1] != '1'
			&& game->map[game->play_y][game->play_x - 1] != 'E')
		ft_move_left(game);
	else if (keyhook == 115 && game->map[game->play_y + 1][game->play_x] != '1'
			&& game->map[game->play_y + 1][game->play_x] != 'E')
		ft_move_down(game);
	else if (keyhook == 100 && game->map[game->play_y][game->play_x + 1] != '1'
			&& game->map[game->play_y][game->play_x + 1] != 'E')
		ft_move_right(game);
	return (0);
}
