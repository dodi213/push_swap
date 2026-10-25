/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharoud <mharoud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:29:59 by mharoud           #+#    #+#             */
/*   Updated: 2026/10/25 15:40:54 by mharoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_mode
{
	MODE_NORMAL = 0,
	MODE_SIMPLE,
	MODE_COMPLEX
}	t_mode;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_config
{
	t_mode			mode;
	int				bench;
	t_node			*stack_a;
	t_node			*stack_b;
}	t_config;

#endif
