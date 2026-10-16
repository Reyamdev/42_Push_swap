/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:36:47 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:39:55 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts how many characters are needed to represent the number as a string.
static size_t	num_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

// Writes the last digit at the current end position and removes that digit.
static void	add_number(size_t *len, char *itoa, long *num)
{
	(*len)--;
	itoa[*len] = (*num % 10) + '0';
	(*num) /= 10;
}

/*
 * Converts integer 'n' into a newly allocated string.
 * First counts how many characters are needed, including a possible '-'.
 * Uses a long so INT_MIN can be safely converted to a positive value.
 * Fills the string from right to left using % 10 to get each digit
 * and + '0' to convert that digit to its character representation.
 * Returns NULL if allocation fails.
 */

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*itoa;

	num = n;
	len = num_len(num);
	itoa = malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (num < 0)
	{
		itoa[0] = '-';
		num *= -1;
		while (len > 1)
			add_number(&len, itoa, &num);
	}
	else
	{
		while (len > 0)
			add_number(&len, itoa, &num);
	}
	return (itoa);
}
