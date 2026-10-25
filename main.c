/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:28:21 by mharoud           #+#    #+#             */
/*   Updated: 2026/10/25 15:29:46 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	cfg;

	if (argc < 2)
		return (0);
	cfg.mode = MODE_NORMAL;
	cfg.bench = 0;
	cfg.stack_a = NULL;
	cfg.stack_b = NULL;
	parse_args(argc, argv, &cfg);
	free_stack(&cfg.stack_a);
	free_stack(&cfg.stack_b);
	return (0);
}
