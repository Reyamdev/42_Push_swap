/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:36:30 by reyam             #+#    #+#             */
/*   Updated: 2026/10/27 15:59:45 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void 	adaptive_sort(t_stack *a, t_stack *b, t_stats *stats, double disorder)
{
	if (disorder < 0.2)
		simple_sort(a, b, stats);
	else if (disorder < 0.5 && disorder >= 0.2)
		medium_sort(a, b, stats);
	else
		complex_sort(a, b, stats);
}
