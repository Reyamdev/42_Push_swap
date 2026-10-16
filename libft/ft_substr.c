/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:54:00 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:48:27 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns a newly allocated substring of 's' starting at index 'start'.
 * Copies at most 'len' characters and adds a terminating '\0'.
 * Returns NULL if allocation fails.
 * Returns an empty allocated string when 'start' is past the end.
 */

static char	*empty_substr(void)
{
	char	*substr;

	substr = malloc(1);
	if (!(substr))
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*substr;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (empty_substr());
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
