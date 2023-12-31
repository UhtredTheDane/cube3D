/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:03:35 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/29 14:03:38 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H

# define BLOCK_H

# include <stdlib.h>
# include <stddef.h>

typedef struct s_block
{
	char	type;
}			t_block;

void	init_block(t_block *block, char symbol);
void	free_block_map(t_block **block_map, size_t index);
#endif
