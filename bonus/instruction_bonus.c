/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:34:47 by reyam             #+#    #+#             */
/*   Updated: 2026/10/28 19:35:10 by reyam            ###   ########.fr       */
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
