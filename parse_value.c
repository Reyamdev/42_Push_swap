/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:10:52 by reyam             #+#    #+#             */
/*   Updated: 2026/10/12 13:25:58 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	is_valid_number(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_number(char *arg, int *value)
{
	long	result;
	int		sign;

	if (!is_valid_number(arg))
		return (0);
	result = 0;
	sign = 1;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	while (*arg)
	{
		result = result * 10 + (*arg - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		arg++;
	}
	*value = (int)(result * sign);
	return (1);
}

static int	is_duplicate(t_stack *stack, int value)
{
	t_node	*curr;

	if (!stack)
		return (0);
	curr = stack->top;
	while (curr)
	{
		if (curr->value == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	parse_and_add(t_stack *a, char *arg)
{
	int		value;
	t_node	*new_node;

	if (!parse_number(arg, &value))
		return (0);
	if (is_duplicate(a, value))
		return (0);
	new_node = create_s_node(value);
	if (!new_node)
		return (0);
	add_to_bottom(a, new_node);
	return (1);
}
