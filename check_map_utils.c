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
	return (1);
}
