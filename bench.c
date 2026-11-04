/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:40:00 by mharoud           #+#    #+#             */
/*   Updated: 2026/11/04 15:40:00 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_str(char *s)
{
	write(2, s, ft_strlen(s));
}

static void	put_nbr(long n)
{
	char	c;

	if (n >= 10)
		put_nbr(n / 10);
	c = '0' + (n % 10);
	write(2, &c, 1);
}

/* disorder is in [0,1]: scale to hundredths of a percent and round. */
static void	put_disorder(double disorder)
{
	long	pct;

	pct = (long)(disorder * 10000.0 + 0.5);
	put_str("[bench] disorder:  ");
	put_nbr(pct / 100);
	put_str(".");
	if (pct % 100 < 10)
		put_str("0");
	put_nbr(pct % 100);
	put_str("%\n");
}

/* Names are in the same order as t_op, separated by a space. */
static void	put_counts(t_ops *ops)
{
	char	*names;
	int		i;
	int		k;

	names = "sa sb ss pa pb ra rb rr rra rrb rrr ";
	i = 0;
	k = 0;
	put_str("[bench] ");
	while (k < OP_COUNT)
	{
		while (names[i] != ' ')
			write(2, &names[i++], 1);
		i++;
		put_str(":  ");
		put_nbr(ops->count[k]);
		if (k == OP_PB)
			put_str("\n[bench] ");
		else if (k == OP_RRR)
			put_str("\n");
		else
			put_str("  ");
		k++;
	}
}

void	print_bench(t_config *cfg)
{
	long	total;
	int		k;

	total = 0;
	k = 0;
	while (k < OP_COUNT)
		total += cfg->ops.count[k++];
	put_disorder(cfg->disorder);
	put_str("[bench] strategy:  ");
	put_str(mode_name(cfg->mode));
	put_str(" / ");
	put_str(mode_cplx(cfg->algo));
	put_str("\n[bench] total_ops:  ");
	put_nbr(total);
	put_str("\n");
	put_counts(&cfg->ops);
}
