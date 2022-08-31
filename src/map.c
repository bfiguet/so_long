/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:47:07 by bfiguet           #+#    #+#             */
/*   Updated: 2022/08/31 14:48:45 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_game *game)
{
	ft_printf("Error\nNeed barrier in the map's limits\n");
	ft_free(game);
	exit(1);
}

void	ft_check_x(t_game *game)
{
	while (game->x < (game->map_x - 1))
	{
		if (game->map[0][game->x] != '1')
			ft_error(game);
		game->x++;
	}
	game->y = game->map_y;
	game->x = 0;
	while (game->x < (game->map_x - 1))
	{
		if (game->map[game->y][game->x] != '1')
			ft_error(game);
		game->x++;
	}
}

void	ft_check_y(t_game *game)
{
	game->x = 0;
	game->y = 0;
	while (game->y <= game->map_y)
	{
		if (game->map[game->y][game->x] != '1')
			ft_error(game);
		game->y++;
	}
	game->y = 0;
	game->x = game->map_x - 1;
	while (game->y <= game->map_y)
	{
		if (game->map[game->y][game->x] != '1')
			ft_error(game);
		game->y++;
	}
}

void	ft_rect_map(char *buff, t_game *game)
{
	int	i;

	i = 0;
	game->map_area = ft_strlen(buff) - game->map_y;
	if (game->map_area != game->map_x * (game->map_y + 1))
	{
		ft_printf("Error\nNeed rectangular map\n");
		free(buff);
		ft_free(game);
		exit(1);
	}
	free(buff);
	ft_check_x(game);
	ft_check_y(game);
}

void	ft_pion(char *buff, t_game *game)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == 'P')
			game->player++;
		if (buff[i] == 'C')
			game->obj_collect++;
		if (buff[i] == 'E')
			game->exit++;
		if (buff[i] == '\n')
			game->map_y++;
		i++;
	}
	if (game->player != 1 || game->obj_collect < 1 || game->exit != 1)
	{
		ft_printf("Error\nNeed 1player, 1 Exit and 1 or more Collectibles\n");
		free(buff);
		exit(1);
	}
}
