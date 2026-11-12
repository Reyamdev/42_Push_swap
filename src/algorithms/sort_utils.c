/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:23:12 by zkotab            #+#    #+#             */
/*   Updated: 2026/11/12 15:50:26 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
** Assign each node a rank based on its value.
** Number of elements smaller than the current value.
** The smallest value gets rank 0, the largest gets rank size - 1.
** This lets the sorting algorithms work with ranks instead of raw values.
*/

void	assign_rank(t_stack *stack)
{
	int		rank;
	t_node	*node_to_rank;
	t_node	*comparison_node;

	node_to_rank = stack->top;
	while (node_to_rank)
	{
		rank = 0;
		comparison_node = stack->top;
		while (comparison_node)
		{
			if (node_to_rank->value > comparison_node->value)
				rank++;
			comparison_node = comparison_node->next;
		}
		node_to_rank->rank = rank;
		node_to_rank = node_to_rank->next;
	}
}

int	ft_sqrt(int nb)
{
	int	root;

	if (nb <= 0)
		return (0);
	root = 1;
	while (root <= nb / root)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (root - 1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
