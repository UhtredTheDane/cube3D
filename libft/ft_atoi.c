/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:42:21 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/18 16:06:39 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* 
 * Description:
 * 
 * Converts the initial portion of the string pointed to nptr 
 * to int representation.
 */

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		negatif;
	int		res;

	i = 0;
	while (ft_isspace(*(nptr + i)))
		i++;
	negatif = 0;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
		if (*(nptr + i++) == '-')
			negatif = 1;
	res = 0;
	if (!ft_strlen(nptr + i))
		return (-1);
	while (ft_isdigit(*(nptr + i)))
	{
		res += (*(nptr + i) - '0');
		i++;
		if (ft_isdigit(*(nptr + i)))
			res *= 10;
	}
	if (negatif)
		res *= -1;
	return (res);
}
