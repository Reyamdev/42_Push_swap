/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:34:47 by reyam             #+#    #+#             */
/*   Updated: 2026/11/08 15:21:14 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	instruction_match(char *line, char *instruction)
{
	size_t	line_len;
	size_t	instruction_len;

	line_len = ft_strlen(line);
	instruction_len = ft_strlen(instruction);
	if (line_len != instruction_len)
		return (0);
	return (ft_strncmp(line, instruction, line_len) == 0);
}

int	valid_instruction(char *line)
{
	if (instruction_match(line, "sa\n"))
		return (1);
	if (instruction_match(line, "sb\n"))
		return (1);
	if (instruction_match(line, "ss\n"))
		return (1);
	if (instruction_match(line, "pa\n"))
		return (1);
	if (instruction_match(line, "pb\n"))
		return (1);
	if (instruction_match(line, "ra\n"))
		return (1);
	if (instruction_match(line, "rb\n"))
		return (1);
	if (instruction_match(line, "rr\n"))
		return (1);
	if (instruction_match(line, "rra\n"))
		return (1);
	if (instruction_match(line, "rrb\n"))
		return (1);
	if (instruction_match(line, "rrr\n"))
		return (1);
	return (0);
}

static void	exec_rotate(char *line, t_stack *a, t_stack *b)
{
	if (instruction_match(line, "ra\n"))
		rotate_backwards(a);
	else if (instruction_match(line, "rb\n"))
		rotate_backwards(b);
	else if (instruction_match(line, "rr\n"))
	{
		rotate_backwards(a);
		rotate_backwards(b);
	}
	else if (instruction_match(line, "rra\n"))
		rotate_forwards(a);
	else if (instruction_match(line, "rrb\n"))
		rotate_forwards(b);
	else if (instruction_match(line, "rrr\n"))
	{
		rotate_forwards(a);
		rotate_forwards(b);
	}
}

void	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (instruction_match(line, "sa\n"))
		swap(a);
	else if (instruction_match(line, "sb\n"))
		swap(b);
	else if (instruction_match(line, "ss\n"))
	{
		swap(a);
		swap(b);
	}
	else if (instruction_match(line, "pa\n"))
		push(a, b);
	else if (instruction_match(line, "pb\n"))
		push(b, a);
	else
	{
		exec_rotate(line, a, b);
	}
}
