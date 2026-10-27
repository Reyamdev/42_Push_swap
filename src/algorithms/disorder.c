/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:43:38 by reyam             #+#    #+#             */
/*   Updated: 2026/10/27 16:00:02 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

double	calculate_disorder(t_stack *stack)
{
	t_node	*outer;
	t_node	*inner;
	int		mistakes;
	int		total_pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	outer = stack->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			total_pairs++;
			if (outer->value > inner->value)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return ((double)mistakes / total_pairs);
}
