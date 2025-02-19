/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:09:13 by asaracut          #+#    #+#             */
/*   Updated: 2025/02/19 04:28:06 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack *init_stack(void) // initialisation de la map
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        ft_exit("malloc stack_init.c ligne 17", stack);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void push(t_stack *stack, int value) // ajouter un element
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        ft_exit("malloc stack_init.c ligne 27", stack);
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}
