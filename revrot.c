/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:29:29 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/29 16:29:30 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **a, t_ops *ops)
{
	reverse_rotate(a);
	op_emit(ops, OP_RRA, "rra\n");
}

void	rrb(t_node **b, t_ops *ops)
{
	reverse_rotate(b);
	op_emit(ops, OP_RRB, "rrb\n");
}

void	rrr(t_node **a, t_node **b, t_ops *ops)
{
	reverse_rotate(a);
	reverse_rotate(b);
	op_emit(ops, OP_RRR, "rrr\n");
}
