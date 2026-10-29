/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:28:46 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/29 16:28:47 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*node_to_move;

	if (!src || !*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_move->prev = NULL;
	node_to_move->next = *dest;
	if (*dest)
		(*dest)->prev = node_to_move;
	*dest = node_to_move;
}

void	pa(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, int print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
