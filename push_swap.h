/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:41:04 by reyam             #+#    #+#             */
/*   Updated: 2026/10/26 17:54:44 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

//bench stuff
typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_operation;

typedef struct s_stats
{
	unsigned long	total;
	unsigned long	operations[OP_COUNT];
}	t_stats;

typedef struct s_runtime
{
	t_config	*config;
	t_stats		*stats;
	double		disorder;
}	t_runtime;

//parsing
t_node	*create_s_node(int value);
void	init_stack(t_stack *stack);
void	add_to_bottom(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);
int		parse_and_add(t_stack *a, char *arg);
int		parse_arguments(t_stack *a, t_config *config, int argc, char **argv);
double	calculate_disorder(t_stack *stack);

//bench
void	init_stats(t_stats *stats);
void	record_operation(t_stats *stats, t_operation op);
void	print_bench(t_stats *stats, double disorder, t_strategy strategy);
//operations
void	sa(t_stack *stack, t_stats *stats);
void	sb(t_stack *stack, t_stats *stats);
void	ss(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	pa(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	pb(t_stack *stack_b, t_stack *stack_a, t_stats *stats);
void	ra(t_stack *stack, t_stats *stats);
void	rb(t_stack *stack, t_stats *stats);
void	rr(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	rra(t_stack *stack, t_stats *stats);
void	rrb(t_stack *stack, t_stats *stats);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_stats *stats);

//sorting util
void	assign_rank(t_stack *stack);
int		ft_sqrt(int nb);
int		is_sorted(t_stack *stack);
//simple sort
void	simple_sort(t_stack *stack_a, t_stack *stack_b, t_stats *stats);

//medium sort
void	medium_sort(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	medium_sortv2(t_stack *stack_a, t_stack *stack_b, t_stats *stats);

void 	complex_sort(t_stack *a, t_stack *b, t_stats *stats);
void	complex_sort_visual(t_stack *a, t_stack *b, t_stats *stats);

//adaptive
void 	adaptive_sort(t_stack *a, t_stack *b, t_stats *stats, double disorder);
# endif
