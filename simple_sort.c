/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:01:14 by zkotab            #+#    #+#             */
/*   Updated: 2026/10/15 15:07:40 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_value(t_stack *stack, t_node *smallest_node)
{
	int		position;
	t_node	*temporary;

	position = 0;
	temporary = stack->top;
	while (temporary != smallest_node)
	{
		position++;
		temporary = temporary->next;
	}
	return (position);
}

static void	shorter_rotate(int position, t_stack *stack, t_stats *stats)
{
	int	rotations;

	rotations = position;
	if (stack->size - position <= position)
	{
		rotations = stack->size - position;
		while (rotations > 0)
		{
			rra(stack, stats);
			rotations--;
		}
	}
	else
	{
		rotations = position;
		while (rotations > 0)
		{
			ra(stack, stats);
			rotations--;
		}
	}
}

static t_node	*find_smallest_node(t_stack *stack)
{
	t_node	*temporary;
	t_node	*smallest_node;
	int		value;

	if (!stack || !stack->top)
		return (NULL);
	value = stack->top->value;
	temporary = stack->top;
	smallest_node = temporary;
	while (temporary)
	{
		if (temporary->value < value)
		{
			value = temporary->value;
			smallest_node = temporary;
		}
		temporary = temporary->next;
	}
	return (smallest_node);
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	size;
	int	position;

	if (!stack_a || !stack_b)
		return ;
	size = stack_a->size;
	position = 0;
	while (size > 0)
	{
		position = find_smallest_value(stack_a, find_smallest_node(stack_a));
		shorter_rotate(position, stack_a, stats);
		pb(stack_b, stack_a, stats);
		size--;
	}
	size = stack_b->size;
	while (size > 0)
	{
		pa(stack_a, stack_b, stats);
		size--;
	}
}
