/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:00:45 by fferschi          #+#    #+#             */
/*   Updated: 2026/11/03 15:02:13 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	biggest(t_node **a)
{
	int		big;
	t_node	*curr;

	if (!a || !*a)
		return (-1);
	big = -1;
	curr = *a;
	while (curr)
	{
		if (curr->smaller > big)
			big = curr->smaller;
		curr = curr->next;
	}
	return (big);
}

void	two_tokens(t_node **a, t_ops *ops)
{
	if ((*a)->smaller > (*a)->next->smaller)
		sa(a, ops);
}

void	three_tokens(t_node **a, t_ops *ops)
{
	if ((*a)->smaller == biggest(a))
		ra(a, ops);
	else if ((*a)->next->smaller == biggest(a))
		rra(a, ops);
	if ((*a)->smaller > (*a)->next->smaller)
		sa(a, ops);
}

void	four_tokens(t_node **a, t_node **b, t_ops *ops)
{
	while ((*a)->smaller != 0)
		ra(a, ops);
	pb(b, a, ops);
	three_tokens(a, ops);
	pa(a, b, ops);
}

void	five_tokens(t_node **a, t_node **b, t_ops *ops)
{
	int		cnt;

	cnt = 0;
	while (cnt < 2 && *a)
	{
		if ((*a)->smaller == 0 || (*a)->smaller == 1)
		{
			pb(b, a, ops);
			cnt++;
		}
		else
			ra(a, ops);
	}
	if ((*b)->smaller < (*b)->next->smaller)
		sb(b, ops);
	three_tokens(a, ops);
	while (*b)
		pa(a, b, ops);
}
