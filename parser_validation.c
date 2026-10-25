/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:28:42 by mharoud           #+#    #+#             */
/*   Updated: 2026/10/25 21:00:29 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	parse_flag(char *str, t_config *cfg)
{
	if (ft_strcmp(str, "--adaptive") == 0)
		cfg->mode == MODE_ADAPTIVE;
	else if (ft_strcmp(str, "--simple") == 0)
		cfg->mode = MODE_SIMPLE;
	else if (ft_strcmp(str, "--medium") == 0)
		cfg->mode = MODE_MEDIUM;
	else if (ft_strcmp(str, "--complex") == 0)
		cfg->mode = MODE_COMPLEX;
	else if (ft_strcmp(str, "--bench") == 0)
		cfg->bench = 1;
	else
		return (0);
	return (1);
}

static int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	append_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*curr;

	if (has_duplicate(*stack, value))
		return (0);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return (1);
	}
	curr = *stack;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	new_node->prev = curr;
	return (1);
}

int	validate_and_add(char *str, t_config *cfg)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = (num * 10) + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
		i++;
	}
	return (append_node(&cfg->stack_a, (int)(num * sign)));
}
