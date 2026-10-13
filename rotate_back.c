/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:02:37 by zkotab            #+#    #+#             */
/*   Updated: 2026/10/13 13:35:26 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	rotate_backwards(t_stack *stack)
{
	t_node	*temporary;

	if (stack == NULL || stack->top == NULL || stack->size < 2)
		return (0);
	temporary = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	temporary->prev = stack->bottom;
	stack->bottom->next = temporary;
	stack->bottom = temporary;
	temporary->next = NULL;
	return (1);
}

void	ra(t_stack *stack)
{
	if (rotate_backwards(stack))
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack)
{
	if (rotate_backwards(stack))
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	a_rotate;
	int	b_rotate;

	a_rotate = rotate_backwards(stack_a);
	b_rotate = rotate_backwards(stack_b);
	if (a_rotate || b_rotate)
		ft_putstr_fd("rr\n", 1);
}
