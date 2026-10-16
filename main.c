/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:42:16 by reyam             #+#    #+#             */
/*   Updated: 2026/10/16 16:07:36 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	print_stack(char *name, t_stack *stack)
{
	t_node	*node;

	printf("%s: TOP -> ", name);
	node = stack->top;
	while (node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("<- BOTTOM\n");
}

static void	init_program(t_stack *a, t_stack *b,
		t_config *config, t_stats *stats)
{
	init_stack(a);
	init_stack(b);
	init_stats(stats);
	config->strategy = STRATEGY_ADAPTIVE;
	config->bench = 0;
}

static int	parse_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static void	run_strategy(t_stack *a, t_stack *b, t_runtime *runtime)
{
	if (runtime->config->strategy == STRATEGY_SIMPLE)
		simple_sort(a, b, runtime->stats);
	else if (runtime->config->strategy == STRATEGY_MEDIUM)
		medium_sort(a, b, runtime->stats);
	else if (runtime->config->strategy == STRATEGY_COMPLEX)
		complex_sort(a, b, runtime->stats);
	else
		adaptive_sort(a, b, runtime->stats, runtime->disorder);
}


//MAIN BELOW - DO NOT TOUCH/////////////////////////////////////////////////////

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;
	t_stats		stats;
	t_runtime	runtime;

	if (argc == 1)
		return (0);
	init_program(&a, &b, &config, &stats);
	if (!parse_arguments(&a, &config, argc, argv))
		return (parse_error(&a, &b));
	runtime.config = &config;
	runtime.stats = &stats;
	runtime.disorder = calculate_disorder(&a);
	run_strategy(&a, &b, &runtime);
	if (config.bench)
		print_bench(&stats, runtime.disorder, config.strategy);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

////////////////////////////////////////////////////////////////////////////////

// int	main(void)
// {
// 	t_stack	a;
// 	t_stack	b;
// 	t_stats	stats;
// 	double	disorder;

// 	init_stack(&a);
// 	init_stack(&b);
// 	init_stats(&stats);

// 	add_to_bottom(&a, create_s_node(1));
// 	add_to_bottom(&a, create_s_node(2));
// 	add_to_bottom(&a, create_s_node(3));
// 	add_to_bottom(&a, create_s_node(4));
// 	add_to_bottom(&a, create_s_node(5));

// 	disorder = calculate_disorder(&a);

// 	printf("BEFORE:\n");
// 	print_stack("A", &a);
// 	print_stack("B", &b);

// 	printf("\nOPERATIONS:\n");
// 	insertion(&a, &b, &stats);

// 	printf("\nAFTER:\n");
// 	print_stack("A", &a);
// 	print_stack("B", &b);

// 	printf("\n");
// 	print_bench(&stats, disorder, STRATEGY_SIMPLE);

// 	free_stack(&a);
// 	free_stack(&b);
// 	return (0);
// }

// int	main(void)
// {
// 	t_stack	stack;
// 	t_node	*curr;

// 	init_stack(&stack);
// 	add_to_bottom(&stack, create_s_node(42));
// 	add_to_bottom(&stack, create_s_node(-3));
// 	add_to_bottom(&stack, create_s_node(10));
// 	add_to_bottom(&stack, create_s_node(99));

// 	assign_rank(&stack);

// 	curr = stack.top;
// 	while (curr)
// 	{
// 		printf("value: %d | rank: %d\n", curr->value, curr->rank);
// 		curr = curr->next;
// 	}
// 	free_stack(&stack);
// 	return (0);
// }
