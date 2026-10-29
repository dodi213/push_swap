/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:29:59 by mharoud           #+#    #+#             */
/*   Updated: 2026/10/29 15:29:57 by mharoud          ###   ########.fr       */
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
	int				bench;
	t_node			*stack_a;
	t_node			*stack_b;
}	t_config;

/* Swap operations */
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);

/* Push operations */
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **b, t_node **a, int print);

/* Rotate operations */
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);

/* Reverse rotate operations */
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);

/* Sorting algorithms */
void	bubble_sort_n_carre(t_node **lst, int print);
void	bucket_sort(t_node **a, t_node **b, int n, int print);
void	radix(t_node **a, t_node **b, int print);

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

int	ft_lstsize(t_node *lst);
char	**ft_split(char const *s, char c);

#endif
