/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:30:19 by aapresya          #+#    #+#             */
/*   Updated: 2022/06/28 21:30:20 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(void)
{
	if (g_data.keys.up)
		move_up();
	if (g_data.keys.down)
		move_down();
	if (g_data.keys.right)
		move_right();
	if (g_data.keys.left)
		move_left();
}

void	move_up(void)
{
	if (g_data.x - 1 >= 0 && g_data.map->matrix[g_data.x - 1][g_data.y] != '1')
	{
		move_util1();
		g_data.x--;
		move_util2();
		g_data.keys.up = 0;
	}
}

void	move_down(void)
{
	if (g_data.x + 1 < g_data.map->height
		&& g_data.map->matrix[g_data.x + 1][g_data.y] != '1')
	{
		move_util1();
		g_data.x++;
		move_util2();
		g_data.keys.down = 0;
	}
}

void	move_right(void)
{
	if (g_data.y + 1 < g_data.map->width
		&& g_data.map->matrix[g_data.x][g_data.y + 1] != '1')
	{
		move_util1();
		g_data.y++;
		move_util2();
		g_data.keys.right = 0;
	}
}

void	move_left(void)
{
	if (g_data.y - 1 >= 0 && g_data.map->matrix[g_data.x][g_data.y - 1] != '1')
	{
		move_util1();
		g_data.y--;
		move_util2();
		g_data.keys.left = 0;
	}
}
