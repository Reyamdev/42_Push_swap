/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:23:12 by zkotab            #+#    #+#             */
/*   Updated: 2026/10/16 16:29:58 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_rank(t_stack *stack)
{
	int	counter;
	t_node	*temporary;
	t_node	*rank_stack;

	rank_stack = stack->top;
	while (rank_stack)
	{
		counter = 0;
		temporary = stack->top;
		while (temporary)
		{
			if (rank_stack->value > temporary->value)
				counter++;
			temporary = temporary->next;
		}
		rank_stack->rank = counter;
		rank_stack = rank_stack->next;
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
