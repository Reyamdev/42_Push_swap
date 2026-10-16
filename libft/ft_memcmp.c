/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 05:14:29 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:56:35 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Compares the first 'n' bytes of memory areas 's1' and 's2'.
 * The memory is treated as unsigned char values so each byte is compared
 * in the range 0 to 255.
 * Returns 0 if all compared bytes are equal, otherwise returns the
 * difference between the first pair of differing bytes.
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*bytes1;
	const unsigned char	*bytes2;
	size_t				i;

	bytes1 = s1;
	bytes2 = s2;
	i = 0;
	while (i < n)
	{
		if (bytes1[i] != bytes2[i])
			return (bytes1[i] - bytes2[i]);
		i++;
	}
	return (0);
}
