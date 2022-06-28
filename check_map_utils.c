/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:30:47 by aapresya          #+#    #+#             */
/*   Updated: 2022/06/28 21:32:26 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_components(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!(map->matrix[i][j] == '1' || map->matrix[i][j] == '0'
				|| map->matrix[i][j] == 'P'))
			{
				if (!(map->matrix[i][j] == 'C' || map->matrix[i][j] == 'E'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_filename(char *file_name)
{
	int		len;
	char	*ptr;

	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	ptr = ft_strrchr(file_name, '.');
	if (!ptr)
		return (0);
	else
		return (!ft_strncmp(ptr, ".ber", 4));
}
