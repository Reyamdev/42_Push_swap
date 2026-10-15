/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:18:11 by reyam             #+#    #+#             */
/*   Updated: 2026/10/15 12:07:37 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

void print_bench(t_stats *stats, double disorder, t_strategy strategy)
{
	//print disorder
	//print strategy name and complexity
	//print stats->total
	//print stats-operations[OP_SA]
	//print stats-operations[OP_SB] etc
	//to STDERR so fd2.
}
