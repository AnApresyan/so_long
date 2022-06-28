#include "so_long.h"

void	ft_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_mlx_pixel_get(t_img *image, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_draw_unit(void)
{
	g_data.inside_x = 0;
	while (g_data.inside_x < g_data.square_size)
	{
		g_data.inside_y = 0;
		while (g_data.inside_y < g_data.square_size)
		{
			g_data.current_sprite = g_data.floor;
			ft_sprite_pixel();
			if (g_data.cell_x == g_data.exit_x && g_data.cell_y == g_data.exit_y
				&& g_data.x == g_data.cell_x && g_data.y == g_data.cell_y)
			{
				g_data.current_sprite = g_data.exit;
				ft_sprite_pixel();
			}
			ft_select_sprite();
			ft_sprite_pixel();
			g_data.inside_y++;
		}
		g_data.inside_x++;
	}
}

void	ft_sprite_pixel(void)
{
	g_data.texx = (int)((float)g_data.inside_x
			/ g_data.square_size * g_data.current_sprite.height);
	g_data.texy = (int)((float)g_data.inside_y
			/ g_data.square_size * g_data.current_sprite.width);
	if (ft_mlx_pixel_get(&g_data.current_sprite, g_data.texy,
			g_data.texx) != 0xFF000000)
		ft_mlx_pixel_put(&g_data.scr.image, g_data.cell_y * g_data.square_size
			+ g_data.inside_y, g_data.cell_x * g_data.square_size
			+ g_data.inside_x, ft_mlx_pixel_get(&g_data.current_sprite,
				g_data.texy, g_data.texx));
}

void	ft_select_sprite(void)
{
	if (g_data.map->matrix[g_data.cell_x][g_data.cell_y] == '1')
		g_data.current_sprite = g_data.wall;
	else if (g_data.map->matrix[g_data.cell_x][g_data.cell_y] == '0')
		g_data.current_sprite = g_data.floor;
	else if (g_data.map->matrix[g_data.cell_x][g_data.cell_y] == 'E')
		g_data.current_sprite = g_data.exit;
	else if (g_data.map->matrix[g_data.cell_x][g_data.cell_y] == 'C')
		g_data.current_sprite = g_data.eatable;
	else if (g_data.map->matrix[g_data.cell_x][g_data.cell_y] == 'P')
		g_data.current_sprite = g_data.player;
}
