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

static void	sort_adaptive(t_config *cfg, int size, int print)
{
	double	disorder;

	disorder = compute_disorder(cfg->stack_a);
	if (size <= 3 || disorder < 0.20)
		bubble_sort_n_carre(&cfg->stack_a, print);
	else if (size <= 100 || disorder < 0.50)
		bucket_sort(&cfg->stack_a, &cfg->stack_b, size, print);
	else
		radix(&cfg->stack_a, &cfg->stack_b, print);
}

static void	execute_sort(t_config *cfg)
{
	int	size;
	int	print;

	size = ft_lstsize(cfg->stack_a);
	if (size < 2 || is_sorted(cfg->stack_a))
		return ;
	print = !cfg->bench;
	index_stack(cfg->stack_a);
	if (cfg->mode == MODE_ADAPTIVE)
		sort_adaptive(cfg, size, print);
	else if (cfg->mode == MODE_SIMPLE)
		bubble_sort_n_carre(&cfg->stack_a, print);
	else if (cfg->mode == MODE_MEDIUM)
		bucket_sort(&cfg->stack_a, &cfg->stack_b, size, print);
	else if (cfg->mode == MODE_COMPLEX)
		radix(&cfg->stack_a, &cfg->stack_b, print);
}

static void	init_config(t_config *cfg)
{
	cfg->mode = MODE_ADAPTIVE;
	cfg->bench = 0;
	cfg->stack_a = NULL;
	cfg->stack_b = NULL;
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
	ft_print_val(cfg.stack_a);
	free_stack(&cfg.stack_a);
	free_stack(&cfg.stack_b);
	return (0);
}
