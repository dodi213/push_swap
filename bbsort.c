/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbsort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:37:27 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/26 16:20:27 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_n_carre(t_list **lst)
{
	unsigned int	len;
	unsigned int	cnt;
	unsigned int	count;
	int				swapped;

	len = ft_lstsize(*lst);
	if (len < 2)
		return ;
	cnt = 0;
	while (cnt < len)
	{
		swapped = 0;
		count = 1;
		while (count < len)
		{
			if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
			{
				sa(lst);
				swapped = 1;
			}
			ra(lst);
			count++;
		}
		ra(lst);
		if (!swapped)
			break ;
		cnt++;
	}
}
