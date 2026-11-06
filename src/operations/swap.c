/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:48:08 by zkotab            #+#    #+#             */
/*   Updated: 2026/11/06 13:28:47 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../libft/libft.h"

/*
** Swap the first two nodes of the stack (sa/sb).
** Save the old top, then make the second node the new top.
** Handle size 2 separately to update the bottom pointer.
** For larger stacks, reconnect the old top to the third node.
** Return 0 if swapping is impossible, otherwise 1.
*/

static int	swap(t_stack *stack)
{
	t_node	*old_top;

	if (stack == NULL || stack->size < 2)
		return (0);
	old_top = stack->top;
	stack->top = old_top->next;
	if (stack->size == 2)
	{
		stack->bottom = old_top;
		stack->top->next = old_top;
		stack->bottom->next = NULL;
		stack->bottom->prev = stack->top;
	}
	else
	{
		old_top->next = old_top->next->next;
		stack->top->next = old_top;
		old_top->prev = stack->top;
		old_top->next->prev = old_top;
	}
	stack->top->prev = NULL;
	return (1);
}

void	sa(t_stack *stack, t_stats *stats)
{
	if (swap(stack))
	{
		record_operation(stats, OP_SA);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack *stack, t_stats *stats)
{
	if (swap(stack))
	{
		record_operation(stats, OP_SB);
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	a_swapped;
	int	b_swapped;

	a_swapped = swap(stack_a);
	b_swapped = swap(stack_b);
	if (a_swapped || b_swapped)
	{
		record_operation(stats, OP_SS);
		ft_putstr_fd("ss\n", 1);
	}
}
