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

void	rra(t_node **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
