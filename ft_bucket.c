/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:35:35 by fferschi          #+#    #+#             */
/*   Updated: 2026/11/04 16:40:00 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	root;

	root = 1;
	while (n / root >= root)
		root++;
	return (root - 1);
}

/* Position (0 = top) of the biggest index left in b. */
static int	max_pos(t_node *b)
{
	int	max;
	int	pos;
	int	i;

	max = b->smaller;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->smaller > max)
		{
			max = b->smaller;
			pos = i;
		}
		i++;
		b = b->next;
	}
	return (pos);
}

/*
** Phase 1: move everything to b, one window of `range` indexes at a time.
** i = how many are already in b. An index <= i is small for this window:
** it goes to the bottom of b (rb). An index in ]i, i + range] stays on top.
** Anything bigger waits in a (ra). When we would do rb then ra, do rr.
*/
static void	push_chunks(t_node **a, t_node **b, int range, t_ops *ops)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->smaller <= i)
		{
			pb(b, a, ops);
			i++;
			if (*a && (*a)->smaller > i + range)
				rr(a, b, ops);
			else
				rb(b, ops);
		}
		else if ((*a)->smaller <= i + range)
		{
			pb(b, a, ops);
			i++;
		}
		else
			ra(a, ops);
	}
}

/* Phase 2: bring the max of b to the top the short way, push it to a. */
static void	push_back(t_node **a, t_node **b, t_ops *ops)
{
	int	pos;
	int	size;

	while (*b)
	{
		size = ft_lstsize(*b);
		pos = max_pos(*b);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, ops);
		}
		else
		{
			while (pos++ < size)
				rrb(b, ops);
		}
		pa(a, b, ops);
	}
}

void	bucket_sort(t_node **a, t_node **b, int n, t_ops *ops)
{
	int	range;

	if (n < 2)
		return ;
	range = ft_sqrt(n) * 3 / 2;
	if (range < 1)
		range = 1;
	push_chunks(a, b, range, ops);
	push_back(a, b, ops);
}
