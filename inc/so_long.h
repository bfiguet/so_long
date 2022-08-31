/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:44:08 by bfiguet           #+#    #+#             */
/*   Updated: 2022/08/31 18:06:25 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <mlx.h>
# include <stdlib.h>
# include<fcntl.h>
# include <unistd.h>
/*
# define PLAYER "./img/player.xpm"
# define WINNER "./img/winner.xpm"
# define LIMIT "./img/limit.xpm"
# define FLOOR "./img/floor.xpm"
# define COLLECT "./img/collect.xpm"
# define EXIT_OPEN "./img/exit_open.xpm"
# define EXIT_CLOSE "./img/exit_close.xpm"
*/
typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	*file;
	int		map_x;
	int		map_y;
	int		map_area;
	int		x;
	int		y;
	int		pxl;
	int		player;
	int		play_x;
	int		play_y;
	int		play_move;
	int		obj_collect;
	int		exit;
	void	*img;
	void	*img_floor;
	void	*img_player;
	void	*img_winner;
	void	*img_exit_open;
	void	*img_exit_close;
	void	*img_collect;
	void	*img_limit;
}		t_game;

//main.c
void	ft_free(t_game *game);
void	ft_valid_map(char **av, t_game *game);
void	ft_ber(char **av);
void	ft_check_arg(int ac, char **av);
int		main(int ac, char **av);

//init.c
char	*ft_init_buff(char **av);
void	ft_init_struct(t_game *game);
void	ft_init_img_ptr(t_game *game);

//move.c
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int		ft_key(int keyhook, t_game *game);

//map.c
void	ft_error(t_game *game);
void	ft_check_x(t_game *game);
void	ft_check_y(t_game *game);
void	ft_rect_map(char *buff, t_game *game);
void	ft_pion(char *buff, t_game *game);

//put.c
void	ft_put_limits(t_game *game);
void	ft_put_floor(t_game *game);
void	ft_put_collect(t_game *game);
void	ft_put_player(t_game *game);
void	ft_put_exit(t_game *game);

//window.c
void	ft_win(t_game *game);
void	ft_destroy_all_img(t_game *game);
int		ft_close_win(t_game *game);
int		ft_total_collect(t_game *game);
void	ft_fill_win(t_game *game);

#endif
