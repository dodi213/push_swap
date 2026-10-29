/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:31:12 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/29 17:00:29 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smaller_init(t_node **a)
{
	t_node	*smallest;
	t_node	*current;
	int		i;
	int		len;

	i = 0;
	len = ft_lstsize(*a);
	while (i < len)
	{
		current = *a;
		smallest = NULL;
		while (current != NULL)
		{
			if ((smallest == NULL || current->value < smallest->value)
				&& current->smaller == -1)
				smallest = current;
			current = current->next;
		}
		if (smallest != NULL)
			smallest->smaller = i;
		i++;
	}
}
