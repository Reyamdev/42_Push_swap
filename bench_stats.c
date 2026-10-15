/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:18:11 by reyam             #+#    #+#             */
/*   Updated: 2026/10/15 14:00:48 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stats(t_stats *stats)
{
	int	i;

	if (!stats)
		return ;
	i = 0;
	stats->total = 0;
	while (i < OP_COUNT)
	{
		stats->operations[i] = 0;
		i++;
	}
}

void	record_operation(t_stats *stats, t_operation op)
{
	if (!stats)
		return ;
	stats->operations[op]++;
	stats->total++;
}
