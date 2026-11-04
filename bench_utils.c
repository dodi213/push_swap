/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:40:00 by mharoud           #+#    #+#             */
/*   Updated: 2026/11/04 15:40:00 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* Every operation goes through here: count it, then print it on stdout. */
void	op_emit(t_ops *ops, t_op op, char *name)
{
	ops->count[op]++;
	if (ops->print)
		write(1, name, ft_strlen(name));
}

char	*mode_name(t_mode mode)
{
	if (mode == MODE_SIMPLE)
		return ("Simple");
	if (mode == MODE_MEDIUM)
		return ("Medium");
	if (mode == MODE_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*mode_cplx(t_mode mode)
{
	if (mode == MODE_SIMPLE)
		return ("O(n^2)");
	if (mode == MODE_MEDIUM)
		return ("O(n\xe2\x88\x9an)");
	return ("O(n log n)");
}
