/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:07:39 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/04 10:28:28 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"

# define ERROR -1

# define WALL '1'

# define SSIZE 40

# define TOP_GAP 0

# define DESTROYMLX 1

# define AUTHORIZED "01CEP"

# define NBSPRITES 5

# define SPRITES "0001COEXPL"

# define THEME "default"

# define K_QUIT 0xff1b
# define K_UP  0x77
# define K_DOWN 0x73
# define K_LEFT 0x61
# define K_RIGHT 0x64

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}			t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	**img;
	int		total_items;
	int		curr_items;
	int		curr_moves;
	int		is_on_exit;
	t_data	*playground;
}			t_param;

typedef struct s_sprite
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;
}		t_sprite;

int		main(int ac, char **av);
int		ft_map_controler(int fd, int *rows);
void	ft_mandatory_char_check(char *line, int *chk);
int		ft_is_yet_char(const char *possibles, int c, int chk);
int		ft_is_line_ok(char *line, size_t size, int *wall_chk);
int		ft_is_line_a_wall(char *line);
int		ft_create_map(int fd, t_map **map, int rows);
int		ft_free_map(t_map *map, int ret_code);
void	ft_add_line(t_map *map, char *line);
int		ft_init_map(t_map *map, int rows);
int		ft_exit_w_message(char *message, char *message2, int fd, int code);
int		ft_free_and_return(char *to_free, int to_return);
int		ft_free_mem(t_map *map, t_param *param, void *mlx, int ret_code);
int		ft_free_param(t_param *param, void *mlx, int ret_code);
int		ft_getmove(int key);
int		ft_render_next_frame(void *param);
int		ft_handle_close(void *param);
int		ft_handle_key(int key, void *param);
int		ft_init_param(t_param **param, void *mlx, void *win, t_map *map);
int		ft_free_param(t_param *param, void *mlx, int ret_code);
void	ft_draw_playground(t_map *map, t_param *param);
void	ft_put_sprite(void *img, t_data *frame, int x, int y);
t_data	*ft_init_frame(t_param *prm);
int		ft_mover(t_param *param, int move);

#endif