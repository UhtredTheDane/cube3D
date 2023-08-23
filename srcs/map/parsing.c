/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:15:54 by agengemb          #+#    #+#             */
/*   Updated: 2023/08/21 18:15:56 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int read_map(char *file_ame)
{
    t_map *map;

    if (open(file_name, O_RDONLY) == -1)
    {
            perror("Can't open %s", file_name);
            return (-1);
    }
    
    map = malloc(sizeof(t_map));
    if (!map)
    {
        printf("Error: Map malloc\n");
        return (-2);
    }
    
}