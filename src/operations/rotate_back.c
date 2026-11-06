/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:02:37 by zkotab            #+#    #+#             */
/*   Updated: 2026/11/06 13:31:55 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../libft/libft.h"

/*
** Rotate the stack upwards (ra/rb): move the top node to the bottom.
** Save the old top, make the next node the new top,
** then link the old top after the bottom node.
** Return 0 if rotation is impossible, otherwise 1.
*/

static int	rotate_backwards(t_stack *stack)
{
	t_node	*old_top;

	if (stack == NULL || stack->top == NULL || stack->size < 2)
		return (0);
	old_top = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	old_top->prev = stack->bottom;
	stack->bottom->next = old_top;
	stack->bottom = old_top;
	stack->bottom->next = NULL;
	return (1);
}

void	ra(t_stack *stack, t_stats *stats)
{
	if (rotate_backwards(stack))
	{
		record_operation(stats, OP_RA);
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_stack *stack, t_stats *stats)
{
	if (rotate_backwards(stack))
	{
		record_operation(stats, OP_RB);
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	a_rotate;
	int	b_rotate;

	a_rotate = rotate_backwards(stack_a);
	b_rotate = rotate_backwards(stack_b);
	if (a_rotate || b_rotate)
	{
		record_operation(stats, OP_RR);
		ft_putstr_fd("rr\n", 1);
	}
}
