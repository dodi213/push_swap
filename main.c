/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:37:27 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/22 17:42:38 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	bubble_sort_n_carre(t_list **lst)
{
	unsigned int	len;
	unsigned int	cnt;
	unsigned int	count;

	cnt = 0;
	len = ft_lstsize(*lst);
	while (cnt < len)
	{
		count = 1;
		while (count < len)
		{
			if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
				sa(lst);
			ra(lst);
			count++;
		}
		ra(lst);
		cnt++;
	}
	ra(lst);
}
