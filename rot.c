/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:29:37 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/29 16:29:38 by fferschi         ###   ########.fr       */
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

void	ra(t_node **a, t_ops *ops)
{
	rotate(a);
	op_emit(ops, OP_RA, "ra\n");
}

void	rb(t_node **b, t_ops *ops)
{
	rotate(b);
	op_emit(ops, OP_RB, "rb\n");
}

void	rr(t_node **a, t_node **b, t_ops *ops)
{
	rotate(a);
	rotate(b);
	op_emit(ops, OP_RR, "rr\n");
}
