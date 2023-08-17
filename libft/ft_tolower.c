/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:45:27 by alexis            #+#    #+#             */
/*   Updated: 2022/07/19 21:05:42 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Description:
 *
 * Convert uppercase letters to lowercase.
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
