/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:42:16 by reyam             #+#    #+#             */
/*   Updated: 2026/10/15 12:08:01 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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


// int	main(void)
// {
// 	t_stack	a;

// 	init_stack(&a);
// 	add_to_bottom(&a, create_s_node(2));
// 	add_to_bottom(&a, create_s_node(1));
// 	add_to_bottom(&a, create_s_node(3));
// 	add_to_bottom(&a, create_s_node(6));
// 	add_to_bottom(&a, create_s_node(5));
// 	add_to_bottom(&a, create_s_node(8));

// 	printf("Before sa:\n");
// 	print_stack(&a);

// 	sa(&a);

// 	printf("After sa:\n");
// 	print_stack(&a);
// 	free_stack(&a);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_stack		a;
// 	t_config	config;

// 	init_stack(&a);
// 	config.bench = 0;
// 	config.strategy = STRATEGY_ADAPTIVE;
// 	if (!parse_arguments(&a, &config, argc, argv))
// 	{
// 		free_stack(&a);
// 		ft_putstr_fd("Error\n", 2);
// 	}
// 	print_stack(&a);
// 	printf("strategy: %d\n", config.strategy);
// 	printf("bench: %d\n", config.bench);

// 	// if (config.strategy == STRATEGY_SIMPLE)
// 	// 	simple_sort(&a);
// 	// else if (config.strategy == STRATEGY_MEDIUM)
// 	// 	medium_sort(&a);
// 	// else if (config.strategy == STRATEGY_COMPLEX)
// 	// 	complex_sort(&a);
// 	// else
// 	// 	adaptive_sort(&a);

// 	free_stack(&a);
// 	return (0);
// }

// int	main(void)
// {
// 	t_stack	a;
// 	t_stack	b;

// 	init_stack(&a);
// 	init_stack(&b);

// 	add_to_bottom(&a, create_s_node(10));
// 	add_to_bottom(&a, create_s_node(20));
// 	add_to_bottom(&a, create_s_node(30));

// 	add_to_bottom(&b, create_s_node(40));
// 	add_to_bottom(&b, create_s_node(50));
// 	add_to_bottom(&b, create_s_node(60));

// 	printf("START\n");
// 	printf("A: ");
// 	print_stack(&a);
// 	printf("B: ");
// 	print_stack(&b);

// 	printf("\n--- RA ---\n");
// 	ra(&a);
// 	printf("A: ");
// 	print_stack(&a);

// 	printf("\n--- RRA ---\n");
// 	rra(&a);
// 	printf("A: ");
// 	print_stack(&a);

// 	printf("\n--- RB ---\n");
// 	rb(&b);
// 	printf("B: ");
// 	print_stack(&b);

// 	printf("\n--- RRB ---\n");
// 	rrb(&b);
// 	printf("B: ");
// 	print_stack(&b);

// 	printf("\n--- RR ---\n");
// 	rr(&a, &b);
// 	printf("A: ");
// 	print_stack(&a);
// 	printf("B: ");
// 	print_stack(&b);

// 	printf("\n--- RRR ---\n");
// 	rrr(&a, &b);
// 	printf("A: ");
// 	print_stack(&a);
// 	printf("B: ");
// 	print_stack(&b);

// 	free_stack(&a);
// 	free_stack(&b);
// 	return (0);
// }
