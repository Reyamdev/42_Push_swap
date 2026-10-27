/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:14:46 by reyam             #+#    #+#             */
/*   Updated: 2026/10/27 15:59:57 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"


//largest rank is a->size - 1

void 	complex_sort(t_stack *a, t_stack *b, t_stats *stats)
{
	int	max_rank;
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	if (is_sorted(a))
		return ;
	assign_rank(a);
	//sort loop prep - how many radix passes per individual bit. represented by max_bits. per bit its N iterations
	max_rank = a->size - 1;
	max_bits = 0;
	while (max_rank > 0)
	{
		max_rank = max_rank >> 1;
		max_bits++;
	}
	//main loop
	bit = 0;
	while (bit < max_bits)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			//inspect current tops bit
			if (((a->top->rank >> bit) & 1) == 0)
			{
				pb(b,a,stats);
			}
			else {
				ra(a, stats);
			}
			i++;
		}
		while (b->top)
		{
			pa(a, b, stats);
		}
		bit++;
	}
}

	// !!The next thing worth reinforcing is why radix processes bit 0 first instead of starting from the highest bit.!!
	// >> operator shifts bits to right.
	// & bitwise AND compares two numbers bit by bit
	// (rank >> bit) & 1 ----> move the bit I care about into the rightmost position, then bitwise-AND that rightmost bit with 1
	// reason why is because in something & 1, 1 acts as a mask so like 00000000000001. anything & 0 = 0, so we just compare last bit for 1.

	//LSD Radix Sort -Least Significant Digit first
	// ra preserves the order of the 1s; pb reverses the 0s,
	// and the later pas reverse those 0s again
	// so both groups preserve their original relative order.
