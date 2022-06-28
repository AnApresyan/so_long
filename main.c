/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:30:05 by aapresya          #+#    #+#             */
/*   Updated: 2022/06/28 21:32:03 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_terminate(int keycode, t_keys *keys)
{
	(void)keycode;
	(void)keys;
	mlx_destroy_window(g_data.scr.mlx, g_data.scr.window);
	exit(0);
	return (0);
}

int	ft_mlx_pressed(int keycode, t_keys *keys)
{
	if (keycode == 53)
		exit(0);
	if ((keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		&& keys->check)
	{
		if (keycode == 13)
			keys->up = 1;
		if (keycode == 1)
			keys->down = 1;
		if (keycode == 2)
			keys->right = 1;
		if (keycode == 0)
			keys->left = 1;
		g_data.keycode = keycode;
		keys->check = 0;
	}
	return (0);
}

int	ft_mlx_released(int keycode, t_keys *keys)
{
	if (g_data.keycode == keycode)
	{
		if (keycode == 13)
			keys->up = 0;
		if (keycode == 1)
			keys->down = 0;
		if (keycode == 2)
			keys->right = 0;
		if (keycode == 0)
			keys->left = 0;
		keys->check = 1;
	}
	printf("Keycode: %d\n", keycode);
	ft_putstr("Moves: ");
	ft_putnbr_fd(g_data.moves, 1);
	ft_putstr("\n");
	return (0);
}

t_parsed	g_data;

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	g_data.map = (t_map *)malloc(sizeof(t_map));
	read_map(argv[1]);
	g_data.scr.mlx = mlx_init();
	ft_get_sprites();
	ft_calculate_resolution();
	g_data.scr.window = mlx_new_window(g_data.scr.mlx,
			g_data.scr.image.width, g_data.scr.image.height, "so_long");
	g_data.scr.image.ptr = mlx_new_image(g_data.scr.mlx,
			g_data.scr.image.width, g_data.scr.image.height);
	g_data.scr.image.addr = mlx_get_data_addr(g_data.scr.image.ptr,
			&g_data.scr.image.bpp, &g_data.scr.image.line_len,
			&g_data.scr.image.endian);
	g_data.keys.check = 1;
	g_data.score = 0;
	g_data.moves = 0;
	mlx_hook(g_data.scr.window, 2, 1L << 0, ft_mlx_pressed, &g_data.keys);
	mlx_hook(g_data.scr.window, 3, 1L << 1, ft_mlx_released, &g_data.keys);
	mlx_hook(g_data.scr.window, 17, 1L << 17, ft_mlx_terminate, &g_data.keys);
	mlx_loop_hook(g_data.scr.mlx, ft_render, NULL);
	mlx_loop(g_data.scr.mlx);
	return (0);
}
