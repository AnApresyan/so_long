/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:30:36 by aapresya          #+#    #+#             */
/*   Updated: 2022/06/28 21:32:57 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (map->matrix[i][0] != '1' && map->matrix[i][map->width - 1] != '1')
			return (0);
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (j < map->width)
			{
				if (map->matrix[i][j] != '1')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	check_widths(char *file_name)
{
	int		fd;
	int		width;
	int		wd;
	char	*line;
	int		r;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_error("File doesn't exist");
	get_next_line(fd, &line);
	width = ft_strlen(line);
	free(line);
	while (1)
	{
		r = get_next_line(fd, &line);
		wd = ft_strlen(line);
		free(line);
		if (!r)
			break ;
		if (wd != width)
			return (0);
	}
	close(fd);
	return (1);
}

int	check_starting_position(void)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (i++ < g_data.map->height)
	{
		j = 0;
		while (j++ < g_data.map->width)
		{
			if (g_data.map->matrix[i][j] == 'P')
			{
				if (found++ == 0)
				{
					g_data.x = i;
					g_data.y = j;
				}
			}
		}
	}
	if (found == 1)
		return (1);
	return (0);
}

int	check_exit(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j] == 'E')
			{
				count++;
				g_data.exit_x = i;
				g_data.exit_y = j;
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	check_collectible(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	g_data.collectibes = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j] == 'C')
				g_data.collectibes++;
			j++;
		}
		i++;
	}
	if (g_data.collectibes != 0)
		return (1);
	return (0);
}
