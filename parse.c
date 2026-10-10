/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 21:53:46 by reyam             #+#    #+#             */
/*   Updated: 2026/10/10 22:39:20 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	parse_flag(char *arg, t_config *config)
{
	if (!ft_strncmp(arg, "--simple",9))
		config->strategy = STRATEGY_SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		config->strategy = STRATEGY_MEDIUM;
	else if (!ft_strncmp(arg,"--complex", 10))
		config->strategy = STRATEGY_COMPLEX;
	else if(!ft_strncmp(arg, "--bench", 8))
		config->bench = 1;
	else if(!ft_strncmp(arg, "--adaptive", 11))
		config->strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	parse_number(char *arg, int *value)
{
	//slightly changed atoi
	// invalid:
	// "abc"
	// "12abc"
	// "--5"
	// ""
	return (1);
}

static int	is_duplicate(t_stack *a, int value)
{

}

int	parse_arguments(t_stack *a, t_config *config, int argc, char **argv)
{
	int	i;
	int	value;
	t_node *new_node;

	i = 1;
	while (i < argc)
	{
		if (!parse_flag(argv[i], config))
		{
			if (!parse_number(argv[i], &value))
				return (0);
			if (is_duplicate(a, value))
				return (0);
			new_node = create_s_node(value);
			if (!new_node)
				return (0);
			add_to_bottom(a, new_node);
		}
		i++;
	}
	return (1);
}
