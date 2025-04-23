/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 05:26:07 by asaracut          #+#    #+#             */
/*   Updated: 2025/04/18 22:39:30 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ft_rra(t_stack *stack)
{
    if (stack->top && stack->top->next) {
        t_node *prev = NULL;
        t_node *last = stack->top;

        while (last->next) {
            prev = last;
            last = last->next;
        }

        prev->next = NULL;
        last->next = stack->top;
        stack->top = last;
    }
}

void rra(t_stack *stack)
{
    ft_rra(stack);
    print("rra\n");
}

void ft_rrb(t_stack *stack)
{
    if (stack->top && stack->top->next) {
        t_node *prev = NULL;
        t_node *last = stack->top;

        while (last->next) {
            prev = last;
            last = last->next;
        }

        prev->next = NULL;
        last->next = stack->top;
        stack->top = last;
    }
}

void rrb(t_stack *stack)
{
    ft_rrb(stack);
    print("rrb\n");
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    ft_rra(stack_a);
    ft_rrb(stack_b);
    print("rrr\n");
}
