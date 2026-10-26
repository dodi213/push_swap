/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:54:17 by mharoud           #+#    #+#             */
/*   Updated: 2026/10/26 16:54:36 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_node **a, int print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
