/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferschi <fferschi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:04:12 by fferschi          #+#    #+#             */
/*   Updated: 2026/10/29 17:11:23 by fferschi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void    ft_print_val(t_node *a)
{
    t_node  *current;

    if (!a)
        return ;
    current = a;
    printf("\n");
    while (current != NULL)
    {
        printf("%i\n", current->value);
        current = current->next;
    }
}