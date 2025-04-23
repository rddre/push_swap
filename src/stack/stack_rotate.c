/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 05:23:52 by asaracut          #+#    #+#             */
/*   Updated: 2025/04/18 22:44:34 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ft_ra(t_stack *stack)
{
    if (stack->top && stack->top->next) {
        t_node *first = stack->top;
        t_node *last = stack->top;

        while (last->next) {
            last = last->next;
        }

        stack->top = first->next;
        first->next = NULL;
        last->next = first;
    }
}

void ra(t_stack *stack)
{
    ft_ra(stack);
    print("ra\n");
}

void ft_rb(t_stack *stack)
{
    if (stack->top && stack->top->next) {
        t_node *first = stack->top;
        t_node *last = stack->top;

        while (last->next) {
            last = last->next;
        }

        stack->top = first->next;
        first->next = NULL;
        last->next = first;
    }
}

void rb(t_stack *stack)
{
    ft_rb(stack);
    print("rb\n");
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ft_ra(stack_a);
    ft_rb(stack_b);
    print("rr\n");
}
