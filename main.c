/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:42:16 by reyam             #+#    #+#             */
/*   Updated: 2026/10/12 14:18:59 by reyam            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	init_stack(&a);
	init_stack(&b);
	config.bench = 0;
	config.strategy = STRATEGY_ADAPTIVE;
	if (!parse_arguments(&a, &config, argc, argv))
	{
		free_stack(&a);
		free_stack(&b);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	printf("START\n");
	printf("A: ");
	print_stack(&a);
	printf("B: ");
	print_stack(&b);

	pb(&a, &b);

	printf("\nAFTER PB\n");
	printf("A: ");
	print_stack(&a);
	printf("B: ");
	print_stack(&b);

	pa(&a, &b);

	printf("\nAFTER PA\n");
	printf("A: ");
	print_stack(&a);
	printf("B: ");
	print_stack(&b);

	free_stack(&a);
	free_stack(&b);
	return (0);
}
