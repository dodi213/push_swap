/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:28:21 by mharoud           #+#    #+#             */
/*   Updated: 2026/11/04 16:25:17 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Decide which algorithm actually runs (adaptive resolves to one of the 3). */
static void	pick_algo(t_config *cfg, int size, t_ops *ops)
{
	cfg->algo = cfg->mode;
	if (cfg->mode != MODE_ADAPTIVE)
		return ;
	if (size <= 5)
		special(&cfg->stack_a, &cfg->stack_b, ops);
	else if (size <= 3 || cfg->disorder < 0.20)
		cfg->algo = MODE_SIMPLE;
	else if (size <= 100 || cfg->disorder < 0.50)
		cfg->algo = MODE_MEDIUM;
	else
		cfg->algo = MODE_COMPLEX;
}

static void	execute_sort(t_config *cfg)
{
	int	size;

	size = ft_lstsize(cfg->stack_a);
	cfg->disorder = compute_disorder(cfg->stack_a);
	pick_algo(cfg, size, ops);
	if (size < 2 || is_sorted(cfg->stack_a))
		return ;
	index_stack(cfg->stack_a);
	if (cfg->algo == MODE_SIMPLE)
		bubble_sort_n_carre(&cfg->stack_a, &cfg->ops);
	else if (cfg->algo == MODE_MEDIUM)
		bucket_sort(&cfg->stack_a, &cfg->stack_b, size, &cfg->ops);
	else
		radix(&cfg->stack_a, &cfg->stack_b, &cfg->ops);
}

static void	init_config(t_config *cfg)
{
	int	i;

	cfg->mode = MODE_ADAPTIVE;
	cfg->algo = MODE_ADAPTIVE;
	cfg->bench = 0;
	cfg->disorder = 0.0;
	cfg->stack_a = NULL;
	cfg->stack_b = NULL;
	cfg->ops.print = 1;
	i = 0;
	while (i < OP_COUNT)
		cfg->ops.count[i++] = 0;
}

int	main(int argc, char **argv)
{
	t_config	cfg;

	if (argc < 2)
		return (0);
	init_config(&cfg);
	parse_args(argc, argv, &cfg);
	smaller_init(&cfg.stack_a);
	execute_sort(&cfg);
	if (cfg.bench)
		print_bench(&cfg);
	free_stack(&cfg.stack_a);
	free_stack(&cfg.stack_b);
	return (0);
}
