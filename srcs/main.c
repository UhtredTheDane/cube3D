/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:58:12 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/08 21:08:52 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main(int argc, char **argv)
{
	size_t	index_format;
	char	*format = ".cub";
	if (argc != 2)
	{
		printf("Usage: ./cube3D YourMap.cub\n");
		return (1);
	}
	index_format = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(argv[1] + index_format, format, 4) != 0)
	{
		printf("Wrong format\n");
		return (2);
	}
	t_canvas *canvas;
	canvas = create_canvas(argv[1]);
 	if (!canvas)
		return (0);
	return (0);
}
