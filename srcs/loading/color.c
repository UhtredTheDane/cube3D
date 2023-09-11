/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:31:23 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/11 20:40:13 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loading.h"

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_value(char **line, char symbol)
{
	char *virgule;
	int color;

	virgule = ft_strchr(*line, symbol);
	*virgule = '\0';
	color = ft_atoi(*line);
	*virgule = symbol;
	if (symbol != '\n')
		*line += (virgule - *line) + 1;
	return (color);
}

int loading_color(t_map *map, char *type, int map_fd)
{
	char *line;
	char *tempo_line;
	int *map_color;
	int t = 0;

	line = trim_backspace(map_fd);
	if (line)
	{
		if (type[0] == 'F')
			map_color = &map->floor_color;
		else
			map_color = &map->ceiling_color;
		// trim avant id
		line = trim_space(line, 0);
		if (ft_strncmp(line, type, 1) == 0)
		{
			// trim entre id et path
			line = trim_space(line, 1);
			tempo_line = line;
			*map_color = create_trgb(t, get_value(&line, ' '), get_value(&line, ' '), get_value(&line, '\n'));
			free(tempo_line);
			return (1);
		}
	}
	return (0);
}
