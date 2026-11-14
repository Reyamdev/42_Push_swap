#include "../../push_swap.h"
#include "../../libft/libft.h"

static void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	parse_numbers_arg(t_stack *a, char *arg)
{
	char	**words;
	int		i;
	int		valid;

	words = ft_split(arg, ' ');
	if (!words)
		return (0);
	i = 0;
	valid = (words[0] != NULL);
	while (words[i] && valid)
	{
		if (!parse_and_add(a, words[i]))
			valid = 0;
		i++;
	}
	free_words(words);
	return (valid);
}