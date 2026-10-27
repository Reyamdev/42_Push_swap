/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:42:16 by reyam             #+#    #+#             */
/*   Updated: 2026/10/27 19:13:13 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

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
