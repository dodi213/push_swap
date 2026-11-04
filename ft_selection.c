/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:50:00 by mharoud           #+#    #+#             */
/*   Updated: 2026/11/04 16:50:00 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Position (0 = top) of the smallest index in a. */
static int	min_pos(t_node *a)
{
	int	min;
	int	pos;
	int	i;

	min = a->smaller;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->smaller < min)
		{
			min = a->smaller;
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

/*
** Min extraction: bring the min of a to the top the short way (ra or rra),
** push it to b. Stop as soon as what is left in a is already sorted:
** everything in b is smaller, so pushing b back gives a sorted a.
** Each step costs at most size / 2 rotations + 1 push -> O(n^2) ops.
*/
void	selection_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	pos;
	int	size;

	while (*a && !is_sorted(*a))
	{
		size = ft_lstsize(*a);
		pos = min_pos(*a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a, ops);
		}
		else
		{
			while (pos++ < size)
				rra(a, ops);
		}
		pb(b, a, ops);
	}
	while (*b)
		pa(a, b, ops);
}
