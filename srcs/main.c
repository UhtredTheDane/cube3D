/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:58:12 by agengemb          #+#    #+#             */
/*   Updated: 2023/08/31 17:59:06 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: ./cube3D YourMap.cub\n");
    return (1);
  }
  size_t index_format;
  index_format = ft_strlen(argv[1]) - 4;
  char *format = ".cub";
  if (ft_strncmp(argv[1] + index_format, format, 4) != 0)
	{
	  printf("Wrong format\n");
    return (2);
  }
	t_queue *queue;
size_t row_nb;
  queue = read_map(argv[1], &row_nb);
  if (!queue)
	  return (0);
  t_canvas *canvas;
  canvas = create_canvas(queue, ft_queuesize(queue), row_nb);
 if (!canvas)
	{
		return (0);
	}

  return (0);
}
