/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:53:12 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Checks whether 'c' is a printable ASCII character.
 * Printable characters are in the range 32 to 126 inclusive.
 * Returns a non-zero value if printable, otherwise returns 0.
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
