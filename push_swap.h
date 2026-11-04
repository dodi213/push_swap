/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:29:59 by mharoud           #+#    #+#             */
/*   Updated: 2026/11/04 16:15:20 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_mode
{
	MODE_ADAPTIVE = 0,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX
}	t_mode;

typedef enum e_op
{
	OP_SA = 0,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_ops
{
	int				print;
	long			count[OP_COUNT];
}	t_ops;

typedef struct s_node
{
	int				value;
	int				smaller;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_config
{
	t_mode			mode;
	t_mode			algo;
	int				bench;
	double			disorder;
	t_ops			ops;
	t_node			*stack_a;
	t_node			*stack_b;
}	t_config;

/* Swap operations */
void	sa(t_node **a, t_ops *ops);
void	sb(t_node **b, t_ops *ops);
void	ss(t_node **a, t_node **b, t_ops *ops);

/* Push operations */
void	pa(t_node **a, t_node **b, t_ops *ops);
void	pb(t_node **b, t_node **a, t_ops *ops);

/* Rotate operations */
void	ra(t_node **a, t_ops *ops);
void	rb(t_node **b, t_ops *ops);
void	rr(t_node **a, t_node **b, t_ops *ops);

/* Reverse rotate operations */
void	rra(t_node **a, t_ops *ops);
void	rrb(t_node **b, t_ops *ops);
void	rrr(t_node **a, t_node **b, t_ops *ops);

/* Sorting algorithms */
void	bubble_sort_n_carre(t_node **lst, t_ops *ops);
void	bucket_sort(t_node **a, t_node **b, int n, t_ops *ops);
void	radix(t_node **a, t_node **b, t_ops *ops);

/* Special case sorting algorithms */
<<<<<<< Updated upstream
void	two_tokens(t_node **a, t_ops *ops);
void	three_tokens(t_node **a, t_ops *ops);
void	four_tokens(t_node **a, t_node **b, t_ops *ops);
void	five_tokens(t_node **a, t_node **b, t_ops *ops);
void	special(t_node **a, t_node **b, t_ops *ops);
=======
void	two_tokens(t_node **a, int print);
void	three_tokens(t_node **a, int print);
void	four_tokens(t_node **a, t_node **b, int print);
void	five_tokens(t_node **a, t_node **b, int print);
void	special(t_node **a, t_node **b);
>>>>>>> Stashed changes

/* Disorder & Indexing */
int		is_sorted(t_node *stack);
void	index_stack(t_node *stack);
double	compute_disorder(t_node *stack);

/* Parser & stack utilities */
int		parse_args(int argc, char **argv, t_config *cfg);
int		parse_flag(char *str, t_config *cfg);
int		validate_and_add(char *str, t_config *cfg);
void	free_split(char **split);
void	free_stack(t_node **stack);
void	exit_error(t_config *cfg);
int		ft_lstsize(t_node *lst);
char	**ft_split(char const *s, char c);

void	smaller_init(t_node **a);

/* Benchmark */
size_t	ft_strlen(const char *s);
void	op_emit(t_ops *ops, t_op op, char *name);
char	*mode_name(t_mode mode);
char	*mode_cplx(t_mode mode);
void	print_bench(t_config *cfg);

#endif
