/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:42:16 by reyam             #+#    #+#             */
/*   Updated: 2026/10/10 20:35:32 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	printf("TOP -> ");
	while (node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("<- BOTTOM\n");
}


int	main(void)
{
	t_stack	a;

	init_stack(&a);
	add_to_bottom(&a, create_s_node(2));
	add_to_bottom(&a, create_s_node(1));
	add_to_bottom(&a, create_s_node(3));
	add_to_bottom(&a, create_s_node(6));
	add_to_bottom(&a, create_s_node(5));
	add_to_bottom(&a, create_s_node(8));

	printf("Before sa:\n");
	print_stack(&a);

	sa(&a);

	printf("After sa:\n");
	print_stack(&a);
	free_stack(&a);
	return (0);
}
