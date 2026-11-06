/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:32:32 by zkotab            #+#    #+#             */
/*   Updated: 2026/11/06 13:31:14 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../libft/libft.h"

/*
** Reverse rotate the stack (rra/rrb): move the bottom node to the top.
** Save the old bottom, make the previous node the new bottom,
** then link the old bottom before the top node.
** Return 0 if rotation is impossible, otherwise 1.
*/

static int	rotate_forwards(t_stack *stack)
{
	t_node	*old_bottom;

	if (stack == NULL || stack->top == NULL || stack->size < 2)
		return (0);
	old_bottom = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	old_bottom->next = stack->top;
	stack->top->prev = old_bottom;
	stack->top = old_bottom;
	stack->top->prev = NULL;
	return (1);
}

void	rra(t_stack *stack, t_stats *stats)
{
	if (rotate_forwards(stack))
	{
		record_operation(stats, OP_RRA);
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stack *stack, t_stats *stats)
{
	if (rotate_forwards(stack))
	{
		record_operation(stats, OP_RRB);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	a_rotate;
	int	b_rotate;

	a_rotate = rotate_forwards(stack_a);
	b_rotate = rotate_forwards(stack_b);
	if (a_rotate || b_rotate)
	{
		record_operation(stats, OP_RRR);
		ft_putstr_fd("rrr\n", 1);
	}
}
