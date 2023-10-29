/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:04:23 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/29 20:38:52 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/block.h"
#include <stdio.h>

void	init_block(t_block *block, char symbol)
{
	block->type = symbol;
}

void	free_block_map(t_block **block_map, size_t index)
{
	size_t	i;
	i = 0;
	while (i < index)
		free(block_map[i++]);
	free(block_map);
}
