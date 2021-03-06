/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:29:59 by aapresya          #+#    #+#             */
/*   Updated: 2022/06/28 21:38:39 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;
	int		r;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (1)
	{
		r = get_next_line(fd, &line);
		free(line);
		if (!r)
			break ;
		height++;
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_strlen(line);
	free(line);
	close(fd);
	return (width);
}

void	read_map(char *file_name)
{
	int		i;

	if (!check_filename(file_name))
		ft_error("File name is wrong");
	if (!check_widths(file_name))
		ft_error("The map is not rectangle");
	g_data.map->height = get_height(file_name);
	g_data.map->width = get_width(file_name);
	g_data.map->matrix = (char **)malloc(sizeof(char *)
			* (g_data.map->height + 1));
	i = 0;
	while (i <= g_data.map->height)
		g_data.map->matrix[i++] = (char *)malloc(sizeof(char)
				* (g_data.map->width + 1));
	read_map_util(file_name);
	check();
}

void	read_map_util(char *file_name)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	int		r;

	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		r = get_next_line(fd, &line);
		j = 0;
		while (j < g_data.map->width)
		{
			g_data.map->matrix[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
		if (!r)
			break ;
	}
	close(fd);
}

void	check(void)
{
	if (!check_walls(g_data.map))
		ft_error("The map is not surrounded by walls");
	if (!check_starting_position())
		ft_error("There is no or multiple starting positions in the map");
	if (!check_exit(g_data.map))
		ft_error("There is no exit in the map");
	if (!check_collectible(g_data.map))
		ft_error("There are no collectibles in the map");
	if (!check_components(g_data.map))
		ft_error("The components of the map are consisted of wrong characters");
}
