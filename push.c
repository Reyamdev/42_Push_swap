/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:02:44 by zkotab            #+#    #+#             */
/*   Updated: 2026/10/15 11:34:01 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

static int	push(t_stack *dest, t_stack *src)
{
	t_node	*temporary;

	if (!src || !src->top || !dest)
		return (0);
	temporary = src->top;
	remove_top(src);
	if (!dest->top)
	{
		dest->top = temporary;
		dest->top->prev = NULL;
		dest->top->next = NULL;
		dest->bottom = temporary;
	}
	else
	{
		dest->top->prev = temporary;
		temporary->prev = NULL;
		temporary->next = dest->top;
		dest->top = temporary;
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

void	pb(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	if (push(stack_b, stack_a))
	{
		record_operation(stats, OP_PB);
		ft_putstr_fd("pb\n", 1);
	}
}
