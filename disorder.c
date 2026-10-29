/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:15:00 by mharoud           #+#    #+#             */
/*   Updated: 2026/10/29 15:15:00 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	index_stack(t_node *stack)
{
	t_node	*curr;
	t_node	*cmp;
	int		rank;

	curr = stack;
	while (curr)
	{
		rank = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < curr->value)
				rank++;
			cmp = cmp->next;
		}
		curr->smaller = rank;
		curr = curr->next;
	}
}

double	compute_disorder(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	long	inversions;
	long	total_pairs;
	int		size;

	size = ft_lstsize(stack);
	if (size < 2)
		return (0.0);
	inversions = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inversions++;
			j = j->next;
		}
		i = i->next;
	}
	total_pairs = ((long)size * (size - 1)) / 2;
	return ((double)inversions / (double)total_pairs);
}
