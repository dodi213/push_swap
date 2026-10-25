#include "push_swap.h"

static int	process_tokens(char **tokens, t_config *cfg)
{
	int	j;

	j = 0;
	while (tokens[j])
	{
		if (tokens[j][0] == '-' && tokens[j][1] == '-')
		{
			if (!parse_flag(tokens[j], cfg))
				return (0);
		}
		else
		{
			if (!validate_and_add(tokens[j], cfg))
				return (0);
		}
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_config *cfg)
{
	char	**tokens;
	int		i;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
		{
			free_split(tokens);
			exit_error(cfg);
		}
		if (!process_tokens(tokens, cfg))
		{
			free_split(tokens);
			exit_error(cfg);
		}
		free_split(tokens);
		i++;
	}
	if (!cfg->stack_a)
		exit_error(cfg);
	return (1);
}
