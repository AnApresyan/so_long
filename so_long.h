#ifndef SO_LONG
# define SO_LONG

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include "./libft/libft.h"
# define BUFFER_SIZE 1

typedef	struct	s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct	s_screen
{
	void		*mlx;
	void		*window;
	t_img		image;
}				t_screen;

typedef struct	s_keys
{
	char		up;
	char		down;
	char		left;
	char		right;
	char		check;
}				t_keys;

typedef struct	s_map
{
	int		height;
	int		width;
	char**		matrix;
}				t_map;

typedef struct	s_parsed
{
	t_screen	scr;
	t_keys		keys;
	t_map		*map;
	int		x;
	int 	y;
	int collectibes;
	int score;
	int exit_x;
	int exit_y;
	int moves;
	t_img	wall;
	t_img	player;
	t_img	floor;
	t_img	exit;
	t_img	eatable;
	int	square_size;
	int cell_x;
	int cell_y;
	int inside_x;
	int inside_y;
	t_img current_sprite;
	int texx;
	int texy;
	int moved;
}				t_parsed;



extern t_parsed	g_data;

char	*the_line(char *tmp);
char	*leftover(char *tmp);
char	*ft_strjoin_gln(char *s1, char *s2);
size_t  ft_strlen_gln(char *str);
int 	get_next_line(int fd, char **line);
void    read_map(char *file_name);
int 	get_width(char *file_name);
int 	get_height(char *file_name);
int 	check_walls(t_map *map);
int 	check_widths(char *file_name);
int 	check_starting_position();
int 	check_exit(t_map *map);
int 	check_collectible(t_map *map);
int 	check_components(t_map *map);
int 	check_filename(char *file_name);
void	check();
void	ft_error(char *str);
void	ft_get_sprites();
void	ft_calculate_resolution();
int		ft_mlx_terminate(int keycode, t_keys *keys);
int		ft_mlx_pressed(int keycode, t_keys *keys);
int		ft_mlx_released(int keycode, t_keys *keys);
int 	ft_render();
void	move_util1();
void	move_util2();
void	move();
void	move_up();
void	move_down();
void	move_right();
void	move_left();
void	ft_mlx_pixel_put(t_img *image, int x, int y, int color);
unsigned int	ft_mlx_pixel_get(t_img *image, int x, int y);
void	ft_draw_unit();
void	ft_sprite_pixel();
void	ft_select_sprite();
void	ft_draw_frame();
void	read_map_util(char *file_name);
void	ft_get_sprites_util(void);

#endif
