/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:58:12 by agengemb          #+#    #+#             */
/*   Updated: 2023/08/17 17:28:30 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main(int argc, char **argv)
{
  size_t index_format;
  
  if (argc != 2)
  {
    printf("Usage: ./cube3D YourMap.cub\n");
    return (1);
  }
  index_format = ft_strlen(argv[1]) - 4;
  char *format = ".cub";

  if (ft_strncmp(argv[1] + index_format, format, 4) != 0)
	{
	printf("Wrong format\n");
    return (2);
   }
  return (0);
}
