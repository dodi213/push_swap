/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:35:35 by fferschi          #+#    #+#             */
/*   Updated: 2026/11/04 17:36:36 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static int	ft_sqrt(int n)
{
	int	root;

	root = 1;
	while (n / root >= root)
		root++;
	root--;
	return (root);
}

static int	n_max(t_node *lst)
{
	int	max;

	if (!lst)
		return (0);
	max = lst->smaller;
	while (lst)
	{
		if (lst->smaller > max)
			max = lst->smaller;
		lst = lst->next;
	}
	return (max);
}

static void	extract_range(t_config *cfg, int inf, int sup, t_ops *ops)
{
	int	i;
	int	size;

	size = ft_lstsize(cfg->stack_a);
	i = 0;
	while (i < size)
	{
		if (cfg->stack_a->smaller > inf && cfg->stack_a->smaller <= sup)
			pb(&cfg->stack_b, &cfg->stack_a, ops);
		else
			ra(&cfg->stack_a, ops);
		i++;
	}
}

static void	return_to_a(t_node **a, t_node **b, t_ops *ops)
{
	bubble_sort_n_carre(b, ops);
	while (*b)
	{
		pa(a, b, ops);
		ra(a, ops);
	}
}

void	bucket_sort(t_config *cfg, int n, t_ops *ops)
{
	int	max;
	int	root;
	int	bucket_num;
	int	limit_inf;
	int	limit_sup;

	root = ft_sqrt(n);
	if (n < 2 || root == 0)
		return ;
	max = n_max(cfg->stack_a);
	bucket_num = 1;
	limit_inf = -1;
	limit_sup = (max / root) * bucket_num;
	while (bucket_num < root)
	{
		extract_range(cfg, limit_inf, limit_sup, ops);
		return_to_a(&cfg->stack_a, &cfg->stack_b, ops);
		bucket_num++;
		limit_inf = limit_sup;
		limit_sup = (max / root) * bucket_num;
	}
	extract_range(cfg, limit_inf, limit_sup, ops);
	return_to_a(&cfg->stack_a, &cfg->stack_b, ops);
}
