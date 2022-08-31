/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:31:48 by bfiguet           #+#    #+#             */
/*   Updated: 2022/08/31 18:17:15 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *game)
{
	int	i;

	i = 0;
	if (game->map[i])
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
}

void	ft_valid_map(char **av, t_game *game)
{
	int		i;
	char	*buff;

	i = 0;
	buff = ft_init_buff(av);
	ft_pion(buff, game);
	game->map = ft_split(buff, '\n');
	while (game->map[0][i] != '\0')
	{
		game->map_x++;
		i++;
	}
	ft_rect_map(buff, game);
}

void	ft_ber(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
		i++;
	if (av[1][--i] != 'r')
	{
		ft_printf("Error\nNeed \"<name>.ber\"\n");
		exit(1);
	}
	if (av[1][--i] != 'e')
	{
		ft_printf("Error\nNeed \"<name>.ber\"\n");
		exit(1);
	}
	if (av[1][--i] != 'b')
	{
		ft_printf("Error\nNeed \"<name>.ber\"\n");
		exit(1);
	}
	if (av[1][--i] != '.')
	{
		ft_printf("Error\nNeed \"<name>.ber\"\n");
		exit(1);
	}
}

void	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nNeed 2 arguments\n");
		exit(0);
	}
	ft_ber(av);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_check_arg(ac, av);
	ft_init_struct(&game);
	ft_valid_map(av, &game);
	ft_win(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, ft_key, &game);
	mlx_hook(game.mlx_win, 17, 1L << 5, ft_close_win, &game);
	mlx_loop_hook(game.mlx_win, ft_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
