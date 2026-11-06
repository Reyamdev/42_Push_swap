/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:02:44 by zkotab            #+#    #+#             */
/*   Updated: 2026/11/06 13:51:03 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../libft/libft.h"

static void	remove_top(t_stack *src)
{
	if (src->size == 1)
	{
		src->top = NULL;
		src->bottom = NULL;
	}
	else
	{
		src->top = src->top->next;
		src->top->prev = NULL;
	}
	src->size -= 1;
}

/*
** Push the top node from the source stack to the destination (pa/pb).
** Save the node, then remove it from the source stack.
** If the destination is empty, make it both top and bottom.
** Otherwise, link the moved node before the current top.
** Update stack sizes without allocating or freeing memory.
** Return 0 if pushing is impossible, otherwise 1.
*/

static int	push(t_stack *dest, t_stack *src)
{
	t_node	*moved_node;

	if (!src || !src->top || !dest)
		return (0);
	moved_node = src->top;
	remove_top(src);
	if (!dest->top)
	{
		dest->top = moved_node;
		dest->top->prev = NULL;
		dest->top->next = NULL;
		dest->bottom = moved_node;
	}
	else
	{
		dest->top->prev = moved_node;
		moved_node->prev = NULL;
		moved_node->next = dest->top;
		dest->top = moved_node;
	}
	dest->size += 1;
	return (1);
}

void	pa(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	if (push(stack_a, stack_b))
	{
		record_operation(stats, OP_PA);
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack *stack_b, t_stack *stack_a, t_stats *stats)
{
	if (push(stack_b, stack_a))
	{
		record_operation(stats, OP_PB);
		ft_putstr_fd("pb\n", 1);
	}
}
