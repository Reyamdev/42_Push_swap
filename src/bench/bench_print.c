/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:57:15 by reyam             #+#    #+#             */
/*   Updated: 2026/10/27 16:01:31 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../libft/libft.h"

static void	put_ulong_fd(unsigned long n, int fd)
{
	if (n >= 10)
		put_ulong_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static void	print_disorder(double disorder)
{
	int	scaled;
	int	whole;
	int	decimal;

	scaled = (int)(disorder * 10000 + 0.5);
	whole = scaled / 100;
	decimal = scaled % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_strategy strategy, double disorder)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Medium / O(n sqrt(n))\n", 2);
	else if (strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (disorder < 0.2)
			ft_putstr_fd("O(n^2)\n", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("O(n sqrt(n))\n", 2);
		else
			ft_putstr_fd("O(n log n)\n", 2);
	}
}

static void	print_operation(char *name, unsigned long count)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	put_ulong_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_stats *stats, double disorder, t_strategy strategy)
{
	if (!stats)
		return ;
	print_disorder(disorder);
	print_strategy(strategy, disorder);
	ft_putstr_fd("[bench] total operations: ", 2);
	put_ulong_fd(stats->total, 2);
	ft_putchar_fd('\n', 2);
	print_operation("sa", stats->operations[OP_SA]);
	print_operation("sb", stats->operations[OP_SB]);
	print_operation("ss", stats->operations[OP_SS]);
	print_operation("pa", stats->operations[OP_PA]);
	print_operation("pb", stats->operations[OP_PB]);
	print_operation("ra", stats->operations[OP_RA]);
	print_operation("rb", stats->operations[OP_RB]);
	print_operation("rr", stats->operations[OP_RR]);
	print_operation("rra", stats->operations[OP_RRA]);
	print_operation("rrb", stats->operations[OP_RRB]);
	print_operation("rrr", stats->operations[OP_RRR]);
}
