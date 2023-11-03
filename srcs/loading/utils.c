/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:24:56 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/25 16:24:57 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loading.h"

char	*create_wrapper(size_t row_nb)
{
	char	*wrapper;
	size_t	i;

	wrapper = malloc(sizeof(char) * (row_nb + 1));
	if (!wrapper)
		return (NULL);
	i = 0;
	while (i < row_nb)
	{
		wrapper[i] = ' ';
		++i;
	}
	wrapper[i] = '\0';
	return (wrapper);
}

void empty_buffer(int map_fd)
{
	char *line = "";

	while (line)
	{
		line = get_next_line(map_fd);
		if (line)
			free(line);
	}
}
char	*trim_backspace(int map_fd)
{
	char	*line;

	line = get_next_line(map_fd);
	while (line && ft_strncmp(line, "\n", 1) == 0)
	{
		free(line);
		line = get_next_line(map_fd);
	}
	return (line);
}

char	*trim_space(char *line, int shifting)
{
	char	*tempo_line;

	tempo_line = ft_strtrim(line + shifting, " ");
	free(line);
	return (tempo_line);
}
