/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 04:17:42 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:49:45 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns a pointer to the last occurrence of 'c' in 's'.
 * The terminating '\0' is also considered part of the string,
 * so searching for '\0' returns a pointer to the terminator.
 * Returns NULL if 'c' is not found.
 */

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (1)
	{
		if (*s == (char)c)
			last = s;
		if (*s == '\0')
			break ;
		s++;
	}
	return ((char *)last);
}
