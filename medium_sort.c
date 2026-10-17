/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 09:45:11 by zkotab            #+#    #+#             */
/*   Updated: 2026/10/17 18:59:27 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_node(t_stack *stack)
{
	t_node	*temporary;
	t_node	*highest_rank;

	if (!stack || !stack->top)
		return (NULL);
	highest_rank = stack->top;
	temporary = stack->top;
	while (temporary)
	{
		if (temporary->rank > highest_rank->rank)
		{
			highest_rank = temporary;
		}
		temporary = temporary->next;
	}
	return (highest_rank);
}

int	find_value(t_stack *stack, t_node *biggest_node)
{
	int		position;
	t_node	*temporary;

	position = 0;
	temporary = stack->top;
	while (temporary != biggest_node)
	{
		position++;
		temporary = temporary->next;
	}
	return (position);
}

void	shorter_rotate(int position, t_stack *stack, t_stats *stats)
{
	int	rotations;

	if (stack->size - position <= position)
	{
		rotations = stack->size - position;
		while (rotations > 0)
		{
			rrb(stack, stats);
			rotations--;
		}
	}
	else
	{
		rotations = position;
		while (rotations > 0)
		{
			rb(stack, stats);
			rotations--;
		}
	}
}

void	clear_b(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	size;
	int	position;

	if (!stack_a || !stack_b)
		return ;
	size = stack_b->size;
	position = 0;
	while (size > 0)
	{
		position = find_value(stack_b, find_node(stack_b));
		shorter_rotate(position, stack_b, stats);
		pa(stack_a, stack_b, stats);
		size--;
	}
}

void	medium_sort(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	chunks_amount;
	int	chunk_size;
	int	rank_min;
	int	rank_max;

	if (is_sorted(stack_a))
		return ;
	assign_rank(stack_a);
	chunks_amount = ft_sqrt(stack_a->size);
	chunk_size = stack_a->size / chunks_amount;
	rank_min = 0;
	rank_max = chunk_size - 1;
	while (stack_a->size != 0)
	{
		if (rank_max == stack_b->size - 1)
		{
			rank_min += chunk_size;
			rank_max += chunk_size;
		}
		if (stack_a->top->rank <= rank_max && stack_a->top->rank >= rank_min)
			pb(stack_b, stack_a, stats);
		else
			ra(stack_a, stats);
	}
	clear_b(stack_a, stack_b, stats);
}
