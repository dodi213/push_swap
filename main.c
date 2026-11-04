/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:28:21 by mharoud           #+#    #+#             */
/*   Updated: 2026/10/29 17:09:41 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Adaptive: the regime comes only from the disorder (subject thresholds).
** 2-5 numbers use a fixed sort (constant ops, inside every regime's bound).
*/
static void	pick_algo(t_config *cfg)
{
	cfg->algo = cfg->mode;
	if (cfg->mode != MODE_ADAPTIVE)
		return ;
	if (cfg->disorder < 0.20)
		cfg->algo = MODE_SIMPLE;
	else if (cfg->disorder < 0.50)
		cfg->algo = MODE_MEDIUM;
	else
		cfg->algo = MODE_COMPLEX;
}

/* Hand-made sorts for 2 to 5 numbers (adaptive mode only). */
static void	sort_small(t_config *cfg, int size)
{
	if (size == 2)
		two_tokens(&cfg->stack_a, &cfg->ops);
	else if (size == 3)
		three_tokens(&cfg->stack_a, &cfg->ops);
	else if (size == 4)
		four_tokens(&cfg->stack_a, &cfg->stack_b, &cfg->ops);
	else
		five_tokens(&cfg->stack_a, &cfg->stack_b, &cfg->ops);
}

static void	execute_sort(t_config *cfg)
{
	int	size;

	size = ft_lstsize(cfg->stack_a);
	cfg->disorder = compute_disorder(cfg->stack_a);
	pick_algo(cfg);
	if (size < 2 || is_sorted(cfg->stack_a))
		return ;
	index_stack(cfg->stack_a);
	if (cfg->mode == MODE_ADAPTIVE && size <= 5)
		sort_small(cfg, size);
	else if (cfg->algo == MODE_SIMPLE)
		selection_sort(&cfg->stack_a, &cfg->stack_b, &cfg->ops);
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
