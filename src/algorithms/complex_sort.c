/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:14:46 by reyam             #+#    #+#             */
/*   Updated: 2026/11/06 15:16:05 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//largest rank is a->size - 1
static void	radix_pass(t_stack *a, t_stack *b, t_stats *stats, int bit)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->top->rank >> bit) & 1) == 0)
			pb(b, a, stats);
		else
			ra(a, stats);
		i++;
	}
	while (b->top)
		pa(a, b, stats);
}

void	complex_sort(t_stack *a, t_stack *b, t_stats *stats)
{
	int	max_rank;
	int	max_bits;
	int	bit;

	if (is_sorted(a))
		return ;
	assign_rank(a);
	max_rank = a->size - 1;
	max_bits = 0;
	while (max_rank > 0)
	{
		max_rank >>= 1;
		max_bits++;
	}
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, stats, bit);
		bit++;
	}
}
