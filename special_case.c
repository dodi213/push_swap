/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:00:45 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/30 19:30:44 by fferschi         ###   ########.fr       */
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

void	two_tokens(t_node **a, int print)
{
	if ((*a)->smaller > (*a)->next->smaller)
		sa(a, print);
}

void	three_tokens(t_node **a, int print)
{
	if ((*a)->smaller == biggest(a))
		ra(a, print);
	else if ((*a)->next->smaller == biggest(a))
		rra(a, print);
	if ((*a)->smaller > (*a)->next->smaller)
		sa(a, print);
}

void	four_tokens(t_node **a, t_node **b, int print)
{
	while ((*a)->smaller != 0)
		ra(a, print);
	pb(b, a, print);
	three_tokens(a, print);
	pa(a, b, print);
}

void	five_tokens(t_node **a, t_node **b, int print)
{
	int		cnt;

	cnt = o;
	while (cnt < 2 && *a)
	{
		if ((*a)->smaller == 0 || (*a)->smaller == 1)
		{
			pb(b, a, print);
			cnt++;
		}
		else
			ra(a, print);
	}
	if ((*b)->smaller < (*b)->next->smaller)
		sb(b, print);
	three_tokens(a, print);
	while (*b)
		pa(a, b, print);
}
