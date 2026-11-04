/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:29:45 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/29 16:29:46 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_node **a, t_ops *ops)
{
	swap(a);
	op_emit(ops, OP_SA, "sa\n");
}

void	sb(t_node **b, t_ops *ops)
{
	swap(b);
	op_emit(ops, OP_SB, "sb\n");
}

void	ss(t_node **a, t_node **b, t_ops *ops)
{
	swap(a);
	swap(b);
	op_emit(ops, OP_SS, "ss\n");
}
