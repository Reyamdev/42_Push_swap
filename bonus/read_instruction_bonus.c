/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:07:54 by reyam             #+#    #+#             */
/*   Updated: 2026/10/28 19:42:18 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*cleanup_read(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

static char	*append_buffer(char *stash, char *buffer, ssize_t bytes_read)
{
	char	*joined;

	buffer[bytes_read] = '\0';
	joined = ft_strjoin(stash, buffer);
	if (!joined)
		return (NULL);
	free(stash);
	return (joined);
}

static char	*read_stdin(char *stash)
{
	char		*buffer;
	char		*temp;
	ssize_t		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (cleanup_read(stash, buffer));
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (cleanup_read(stash, buffer));
		if (bytes_read == 0)
			break ;
		temp = append_buffer(stash, buffer, bytes_read);
		if (!temp)
			return (cleanup_read(stash, buffer));
		stash = temp;
	}
	if (stash[0] == '\0')
		return (cleanup_read(stash, buffer));
	free(buffer);
	return (stash);
}

static char	*extract_instruction(char **stash)
{
	char	*line;
	char	*leftover;

	line = extract_instruction_line(*stash);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	leftover = extract_instruction_leftover(*stash);
	if (!leftover)
	{
		free(line);
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	free(*stash);
	*stash = leftover;
	return (line);
}

char	*read_instruction(void)
{
	static char	*stash;
	char		*line;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_stdin(stash);
	if (!stash)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
	{
		line = stash;
		stash = NULL;
		return (line);
	}
	return (extract_instruction(&stash));
}
