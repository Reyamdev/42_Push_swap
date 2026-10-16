/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:20:12 by reyam             #+#    #+#             */
/*   Updated: 2026/09/11 15:27:28 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of words in 'str', using 'c' as the delimiter.
static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

// Allocates one word starting at 's' and stores its length in 'len'.
static char	*make_word(const char *s, char c, size_t *len)
{
	char	*word;

	*len = 0;
	while (s[*len] && s[*len] != c)
		(*len)++;
	word = malloc(sizeof(char) * (*len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, *len + 1);
	return (word);
}

// Frees all successfully allocated words and the outer array.
static void	free_split(char **split, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Extracts each word from 's' and stores it in the 'split' array.
static int	split_fill(char **split, char const *s, char c)
{
	size_t	i;
	size_t	word_index;
	size_t	word_len;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			split[word_index] = make_word(s + i, c, &word_len);
			if (!split[word_index])
			{
				free_split(split, word_index);
				return (0);
			}
			word_index++;
			i += word_len;
		}
	}
	split[word_index] = NULL;
	return (1);
}

// Splits 's' by delimiter 'c' into a NULL-terminated array of new strings.
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;

	word_count = count_words(s, c);
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	if (!split_fill(split, s, c))
		return (NULL);
	return (split);
}
