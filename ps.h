#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_mode
{
	MODE_NORMAL = 0,
	MODE_SIMPLE,
	MODE_COMPLEX
}	t_mode;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_config
{
	t_mode	mode;
	int		bench;
	t_node	*stack_a;
	t_node	*stack_b;
}	t_config;

/* Parser Prototypes */
int		parse_args(int argc, char **argv, t_config *cfg);
void	free_split(char **split);
void	exit_error(t_config *cfg);
void	free_stack(t_node **stack);

#endif
