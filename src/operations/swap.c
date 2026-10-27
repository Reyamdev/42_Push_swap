/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:48:08 by zkotab            #+#    #+#             */
/*   Updated: 2026/10/27 16:02:12 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../libft/libft.h"

static int	swap(t_stack *stack)
{
	t_node	*temporary;

	if (stack == NULL || stack->size < 2)
		return (0);
	temporary = stack->top;
	stack->top = temporary->next;
	if (stack->size == 2)
	{
		stack->bottom = temporary;
		stack->top->next = temporary;
		stack->bottom->next = NULL;
		stack->bottom->prev = stack->top;
	}
	else
	{
		temporary->next = temporary->next->next;
		stack->top->next = temporary;
		temporary->prev = stack->top;
		temporary->next->prev = temporary;
	}
	stack->top->prev = NULL;
	return (1);
}

/*
** swap flow:
**
** before:
** TOP -> [10] <-> [20] <-> [30] <- BOTTOM
**
** after sa:
** TOP -> [20] <-> [10] <-> [30] <- BOTTOM
**
** first  = 10 (old top)
** second = 20 (new top)
** third  = 30 (rest of stack, can be NULL)
**
** 1. second becomes the new top
** 2. first moves directly below second
** 3. first reconnects to third
** 4. if third does not exist, first becomes the new bottom
**
** size < 2: do nothing
*/

// static int	swapv1(t_stack *stack)
// {
// 	t_node	*first;
// 	t_node	*second;
// 	t_node	*third;

// 	if (!stack || stack->size < 2)
// 		return (0);
// 	first = stack->top;
// 	second = first->next;
// 	third = second->next;
// 	second->prev = NULL;
// 	second->next = first;
// 	first->next = third;
// 	first->prev = second;
// 	if (third)
// 		third->prev = first;
// 	else
// 		stack->bottom = first;
// 	stack->top = second;
// 	return (1);
// }

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
