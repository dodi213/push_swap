/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:00:05 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/28 17:32:16 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	n_max(t_node *lst)
{
	int	max;

	if (!lst)
		return (0);
	max = lst->smaller;
	while (lst)
	{
		if (lst->smaller > max)
			max = lst->smaller;
		lst = lst->next;
	}
	return (max);
}

static int	size_bi(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 2;
	}
	return (i);
}

void	radix(t_node **a, t_node **b)
{
	int	i;
	int	j;
	int	len;
	int	max_size;

	if (!a || !*a)
		return ;
	i = 0;
	len = ft_lstsize(*a);
	max_size = size_bi(n_max(*a));
	while (i < max_size)
	{
		j = 0;
		while (j < len)
		{
			if ((((*a)->smaller >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
