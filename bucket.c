/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:35:35 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/26 16:53:51 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

typedef struct s_list
{
	int				smaller;
	struct s_list	*next;
}	t_list;

/*
** À fournir par ton projet (convention push_swap standard) :
** pa : sommet de b -> sommet de a
** pb : sommet de a -> sommet de b
** ra : le sommet de a passe tout en bas
** ft_sort : trie b, plus petit au sommet
*/
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	bubble_sort_n_carre(t_list **lst);

/* Racine entière : plus grand r tel que r * r <= n */
int	ft_sqrt(int n)
{
	int	root;

	root = 1;
	while (n / root >= root)
		root++;
	root--;
	return (root);
}

int	n_max(t_list *lst)
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

int	bucket_limit(int max, int root)
{
	return (max / root);
}

/* Parcourt les n éléments de a : ceux de ]inf, sup] partent dans b,
** les autres sont envoyés en bas de a. */
static void	extract_range(t_list **a, t_list **b, int n, int inf, int sup)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((*a)->smaller > inf && (*a)->smaller <= sup)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

/* Trie b puis remet ses éléments en bas de a, dans l'ordre croissant. */
static void	return_to_a(t_list **a, t_list **b)
{
	bubble_sort_n_carre(b)
	while (*b)
	{
		pb(a, b);
		ra(a);
	}
}

/* Hypothèse : valeurs >= 1 (par ex. rangs 1..n). n = taille de a. */
void	bucket_sort(t_list **a, t_list **b, int n)
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
	limit_sup = bucket_limit(max, root) * bucket_num;
	while (bucket_num < root)
	{
		extract_range(a, b, n, limit_inf, limit_sup);
		return_to_a(a, b);
		bucket_num++;
		limit_inf = limit_sup;
		limit_sup = bucket_limit(max, root) * bucket_num;
	}
	extract_range(a, b, n, limit_inf, max);
	return_to_a(a, b);
}