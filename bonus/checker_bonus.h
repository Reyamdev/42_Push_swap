/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:41:04 by reyam             #+#    #+#             */
/*   Updated: 2026/10/29 20:08:46 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../push_swap.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*read_instruction(void);
char	*extract_instruction_line(char *stash);
char	*extract_instruction_leftover(char *stash);
int		valid_instruction(char *line);
void	execute_instruction(char *line, t_stack *a, t_stack *b);

// operations
void	push(t_stack *dest, t_stack *src);
void	rotate_backwards(t_stack *stack);
void	rotate_forwards(t_stack *stack);
void	swap(t_stack *stack);

#endif
