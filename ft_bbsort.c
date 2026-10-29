/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bbsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:37:27 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/29 16:15:00 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bubble_pass(t_node **lst, unsigned int len, int print)
{
	unsigned int	count;
	int				swapped;

	swapped = 0;
	count = 1;
	while (count < len)
	{
		if ((*lst)->value > (*lst)->next->value)
		{
			sa(lst, print);
			swapped = 1;
		}
		ra(lst, print);
		count++;
	}
	ra(lst, print);
	return (swapped);
}

void	bubble_sort_n_carre(t_node **lst, int print)
{
	unsigned int	len;
	unsigned int	cnt;

	len = ft_lstsize(*lst);
	if (len < 2)
		return ;
	cnt = 0;
	while (cnt < len)
	{
		if (!bubble_pass(lst, len, print))
			break ;
		cnt++;
	}
}
