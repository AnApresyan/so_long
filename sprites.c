#include "so_long.h"

void	ft_calculate_resolution(void)
{
	int	screen_w;
	int	screen_h;

	mlx_get_screen_size(g_data.scr.mlx, &screen_w, &screen_h);
	if (g_data.map->height > g_data.map->width)
		g_data.square_size = 0.7 * screen_h / g_data.map->height;
	else
		g_data.square_size = 0.7 * screen_w / g_data.map->width;
	g_data.scr.image.width = g_data.square_size * g_data.map->width;
	g_data.scr.image.height = g_data.square_size * g_data.map->height;
}

void	ft_get_sprites(void)
{
	g_data.wall.ptr = mlx_xpm_file_to_image(g_data.scr.mlx, "img/wall.xpm",
			&g_data.wall.width, &g_data.wall.height);
	if (!(g_data.wall.ptr))
	{
		ft_error("Failed to allocate memory for the wall texture.");
	}
	g_data.wall.addr = mlx_get_data_addr(g_data.wall.ptr,
			&g_data.wall.bpp, &g_data.wall.line_len, &g_data.wall.endian);
	g_data.player.ptr = mlx_xpm_file_to_image(g_data.scr.mlx, "img/player.xpm",
			&g_data.player.width, &g_data.player.height);
	if (!(g_data.player.ptr))
	{
		ft_error("Failed to allocate memory for the player texture.");
	}
	g_data.player.addr = mlx_get_data_addr(g_data.player.ptr,
			&g_data.player.bpp, &g_data.player.line_len, &g_data.player.endian);
	g_data.exit.ptr = mlx_xpm_file_to_image(g_data.scr.mlx, "img/exit.xpm",
			&g_data.exit.width, &g_data.exit.height);
	if (!(g_data.exit.ptr))
	{
		ft_error("Failed to allocate memory for the exit texture.");
	}
	ft_get_sprites_util();
}

void	ft_get_sprites_util(void)
{
	g_data.exit.addr = mlx_get_data_addr(g_data.exit.ptr, &g_data.exit.bpp,
			&g_data.exit.line_len, &g_data.exit.endian);
	g_data.floor.ptr = mlx_xpm_file_to_image(g_data.scr.mlx, "img/floor.xpm",
			&g_data.floor.width, &g_data.floor.height);
	if (!(g_data.floor.ptr))
	{
		ft_error("Failed to allocate memory for the floor texture.");
	}
	g_data.floor.addr = mlx_get_data_addr(g_data.floor.ptr, &g_data.floor.bpp,
			&g_data.floor.line_len, &g_data.floor.endian);
	g_data.eatable.ptr = mlx_xpm_file_to_image(g_data.scr.mlx,
			"img/eatable.xpm", &g_data.eatable.width, &g_data.eatable.height);
	if (!(g_data.eatable.ptr))
	{
		ft_error("Failed to allocate memory for the eatable texture.");
	}
	g_data.eatable.addr = mlx_get_data_addr(g_data.eatable.ptr,
			&g_data.eatable.bpp, &g_data.eatable.line_len,
			&g_data.eatable.endian);
}
