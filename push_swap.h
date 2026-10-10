/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:41:04 by reyam             #+#    #+#             */
/*   Updated: 2026/10/10 22:44:49 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

// ra  = top becomes bottom
// rra = bottom becomes top

typedef struct s_node
{
	int				value;
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

//parsing
t_node	*create_s_node(int value);
void	init_stack(t_stack *stack);
void	add_to_bottom(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);
int		parse_arguments(t_stack *a, t_config *config, int argc, char **argv);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

#endif
