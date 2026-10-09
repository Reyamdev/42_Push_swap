/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:40:38 by reyam             #+#    #+#             */
/*   Updated: 2026/10/09 19:45:15 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_s_node(int value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	push_to_stack(t_stack *stack, t_node *new_node)
{
	if (!stack->size)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		stack->size = 1;
	}
	else {
		stack->top->next = new_node;
		new_node->prev = stack->top;
		stack->top = new_node;
		stack->size += 1;
	}
}
