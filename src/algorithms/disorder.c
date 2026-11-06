/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:43:38 by reyam             #+#    #+#             */
/*   Updated: 2026/11/06 12:30:12 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
** Disorder = inversions / total pairs.
** An inversion is when an earlier number is bigger than a later one.
*/

double	calculate_disorder(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		inversions;
	int		pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	inversions = 0;
	pairs = 0;
	first = stack->top;
	while (first)
	{
		second = first->next;
		while (second)
		{
			pairs++;
			if (first->value > second->value)
				inversions++;
			second = second->next;
		}
		first = first->next;
	}
	return ((double)inversions / pairs);
}
