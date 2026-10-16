/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:11:13 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:10:32 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Finds the first and last characters in 's1' that are not in 'set',
 * then returns a newly allocated substring between those positions.
 * Characters from 'set' are removed only from the beginning and end.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		length;
	size_t		i;
	char		*trimstr;

	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	length = end - start;
	trimstr = malloc(sizeof(char) * (length + 1));
	if (!trimstr)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimstr[i] = s1[start];
		start++;
		i++;
	}
	trimstr[i] = '\0';
	return (trimstr);
}
