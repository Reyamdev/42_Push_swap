/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:07:52 by reyam             #+#    #+#             */
/*   Updated: 2026/10/28 19:49:25 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// 1. Parse argv into stack A
//    - validate ints
//    - validate range
//    - validate duplicates
//    - stack B starts empty

// 2. Read instructions from stdin
//    - read_instruction()
//    - one line at a time

// 3. Validate each instruction
//    - "sa\n", "pb\n", "rrr\n", etc.
//    - anything else => Error

// 4. Execute the instruction silently
//    - modify A/B
//    - do NOT print the operation

// 5. Repeat until EOF

// 6. Final check
//    - A sorted AND B empty -> "OK\n"
//    - otherwise -> "KO\n"

// 7. Free both stacks and exit

static int	checker_error(t_stack *a, t_stack *b, char *line)
{
	free(line);
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	parse_checker_arguments(t_stack *a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_and_add(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (argc == 1)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (!parse_checker_arguments(&a, argc, argv))
		return (checker_error(&a, &b, NULL));
	line = read_instruction();
	while (line)
	{
		if (!valid_instruction(line))
			return (checker_error(&a, &b, line));
		execute_instruction(line, &a, &b);
		free(line);
		line = read_instruction();
	}
	if (is_sorted(&a) && b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
