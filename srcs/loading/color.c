/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:31:23 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/18 16:17:43 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loading.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_value(char **line, char symbol)
{
	char	*virgule;
	int		color;

	virgule = ft_strchr(*line, symbol);
	if (!virgule)
		return (-1);
	*virgule = '\0';
	color = ft_atoi(*line);
	if (color < 0 || color > 255)
		return (-1);
	*virgule = symbol;
	if (symbol != '\n')
		*line += (virgule - *line) + 1;
	return (color);
}

int	loading_trgb(char *line)
{
	int	r;
	int	g;
	int	b;

	r = get_value(&line, ',');
	if (r == -1)
		return (-1);
	g = get_value(&line, ',');
	if (g == -1)
		return (-1);
	b = get_value(&line, '\n');
	if (b == -1)
		return (-1);
	return (create_trgb(0, r, g, b));
}

int	loading_color(t_map *map, char *line, char type)
{
	char	*tempo_line;
	int		*map_color;

	line = trim_space(line, 2);
	if (line)
	{
		if (type == 'F')
			map_color = &map->floor_color;
		else
			map_color = &map->ceiling_color;
		tempo_line = line;
		*map_color = loading_trgb(line);
		if (*map_color == -1)
		{
			free(tempo_line);
			printf("error trgb format\n");
			return (0);
		}
		free(tempo_line);
		return (1);
	}
	free(line);
	return (0);
}
