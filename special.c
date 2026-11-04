/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:22:57 by fferschi          #+#    #+#             */
/*   Updated: 2026/11/04 16:14:45 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	special(t_node **a, t_node **b, t_ops *ops)
{
	if (ft_lstsize(a) == 5)
		five_tokens(a, b, ops);
	else if (ft_lstsize(a) == 4)
		four_tokens(a, b, ops);
	else if (ft_lstsize(a) == 3)
		three_tokens(a, b, ops);
	else if (ft_lstsize(a) == 2)
		two_tokens(a, b, ops);
}
