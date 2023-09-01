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
