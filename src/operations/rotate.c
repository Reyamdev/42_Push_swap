/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:32:32 by zkotab            #+#    #+#             */
/*   Updated: 2026/10/27 16:02:06 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../libft/libft.h"

static int	rotate_forwards(t_stack *stack)
{
	t_node	*temporary;

	if (stack == NULL || stack->top == NULL || stack->size < 2)
		return (0);
	temporary = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	temporary->next = stack->top;
	stack->top->prev = temporary;
	stack->top = temporary;
	temporary->prev = NULL;
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
