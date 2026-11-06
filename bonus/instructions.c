/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:58:14 by zkotab            #+#    #+#             */
/*   Updated: 2026/11/06 14:15:27 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	push(t_stack *dest, t_stack *src)
{
	t_node	*moved_node;

	if (!src || !src->top || !dest)
		return ;
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
}

void	rotate_backwards(t_stack *stack)
{
	t_node	*old_top;

	if (stack == NULL || stack->top == NULL || stack->size < 2)
		return ;
	old_top = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	old_top->prev = stack->bottom;
	stack->bottom->next = old_top;
	stack->bottom = old_top;
	old_top->next = NULL;
}

void	rotate_forwards(t_stack *stack)
{
	t_node	*old_bottom;

	if (stack == NULL || stack->top == NULL || stack->size < 2)
		return ;
	old_bottom = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	old_bottom->next = stack->top;
	stack->top->prev = old_bottom;
	stack->top = old_bottom;
	old_bottom->prev = NULL;
}

void	swap(t_stack *stack)
{
	t_node	*old_top;

	if (stack == NULL || stack->size < 2)
		return ;
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
}
