/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:51:32 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Fills 'len' bytes of memory at 'b' with the value 'c',
 * converted to unsigned char.
 */

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	x;
	size_t			i;

	p = str;
	x = c;
	i = 0;
	while (i < len)
	{
		p[i] = x;
		i++;
	}
	return (str);
}
