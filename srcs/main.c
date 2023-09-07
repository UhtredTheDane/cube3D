/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:58:12 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/07 23:02:24 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main(int argc, char **argv)
{
	size_t	index_format;
	char	*format = ".cub";
	size_t	row_nb;
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
	t_list *list;
 	row_nb = 0;
	list = read_map(argv[1], &row_nb); 
	if (!list)
		return (0);
	t_canvas *canvas;
	canvas = create_canvas(list, ft_lstsize(list), row_nb);
 	if (!canvas)
		return (0);
	return (0);
}
