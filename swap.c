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

void	sa(t_node **a, int print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
