/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:41:04 by reyam             #+#    #+#             */
/*   Updated: 2026/10/09 19:45:40 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

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

t_node *create_s_node(int value);
void	init_stack(t_stack *stack);
void	push_to_stack(t_stack *stack, t_node *new_node);

#endif
