#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_node **stack)
{
	t_node	*curr;
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_config *cfg)
{
	if (cfg)
	{
		free_stack(&cfg->stack_a);
		free_stack(&cfg->stack_b);
	}
	write(2, "Error\n", 6);
	exit(1);
}
