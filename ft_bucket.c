/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:35:35 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/28 16:44:27 by fferschi         ###   ########.fr       */
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

/* Parcourt les n éléments de a : ceux de ]inf, sup] partent dans b,
** les autres sont envoyés en bas de a. */
static void	extract_range(t_node **a, t_node **b, int inf, int sup)
{
	int	i;
	int	size;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		if ((*a)->smaller > inf && (*a)->smaller <= sup)
			pb(b, a);
		else
			ra(a);
		i++;
	}
}

/* Trie b puis remet ses éléments en bas de a, dans l'ordre croissant. */
static void	return_to_a(t_node **a, t_node **b)
{
	bubble_sort_n_carre(b);
	while (*b)
	{
		pb(b, a);
		ra(a);
	}
}

/* Hypothèse : valeurs >= 1 (par ex. rangs 1..n). n = taille de a. */
void	bucket_sort(t_node **a, t_node **b, int n)
{
	int	max;
	int	root;
	int	bucket_num;
	int	limit_inf;
	int	limit_sup;

	root = ft_sqrt(n);
	if (n < 2 || root == 0)
		return ;
	max = n_max(*a);
	bucket_num = 1;
	limit_inf = -1;
	limit_sup = (max / root) * bucket_num;
	while (bucket_num < root)
	{
		extract_range(a, b, limit_inf, limit_sup);
		return_to_a(a, b);
		bucket_num++;
		limit_inf = limit_sup;
		limit_sup = (max / root) * bucket_num;
	}
	extract_range(a, b, n, limit_inf, max);
	return_to_a(a, b);
}
