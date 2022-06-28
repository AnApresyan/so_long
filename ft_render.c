#include "so_long.h" 

void	ft_draw_frame(void)
{
	g_data.cell_x = 0;
	while (g_data.cell_x < g_data.map->height)
	{
		g_data.cell_y = 0;
		while (g_data.cell_y < g_data.map->width)
		{
			ft_draw_unit();
			g_data.cell_y++;
		}
		g_data.cell_x++;
	}
}

int	ft_render(void)
{
	move();
	ft_draw_frame();
	mlx_put_image_to_window(g_data.scr.mlx,
		g_data.scr.window, g_data.scr.image.ptr, 0, 0);
	mlx_string_put(g_data.scr.mlx, g_data.scr.window, 25, 25, 0x00FF0000, " ");
	mlx_do_sync(g_data.scr.mlx);
	return (0);
}

void	move_util1(void)
{
	g_data.moves++;
	if (g_data.x == g_data.exit_x && g_data.y == g_data.exit_y)
		g_data.map->matrix[g_data.x][g_data.y] = 'E';
	else
		g_data.map->matrix[g_data.x][g_data.y] = '0';
}

void	move_util2(void)
{
	if (g_data.map->matrix[g_data.x][g_data.y] == 'C')
		g_data.score++;
	if (g_data.map->matrix[g_data.x][g_data.y] == 'E'
		&& g_data.score == g_data.collectibes)
		ft_error("Won");
	g_data.map->matrix[g_data.x][g_data.y] = 'P';
}
