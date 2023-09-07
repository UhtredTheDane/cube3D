/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:04:23 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/07 23:04:25 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/block.h"

void	free_block_map(t_block **block_map, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(block_map[i]);
		++i;
	}
	free(block_map);
}
