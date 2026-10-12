/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 21:53:46 by reyam             #+#    #+#             */
/*   Updated: 2026/10/12 13:16:47 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	parse_flag(char *arg, t_config *config)
{
	if (!ft_strncmp(arg, "--simple", 9))
		config->strategy = STRATEGY_SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		config->strategy = STRATEGY_MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 10))
		config->strategy = STRATEGY_COMPLEX;
	else if (!ft_strncmp(arg, "--bench", 8))
		config->bench = 1;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		config->strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_arguments(t_stack *a, t_config *config, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_flag(argv[i], config))
		{
			if (!parse_and_add(a, argv[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
