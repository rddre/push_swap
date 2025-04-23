/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 05:18:36 by asaracut          #+#    #+#             */
/*   Updated: 2025/04/18 22:52:20 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ft_sa(t_stack *stack)
{
    if (stack->top && stack->top->next) {
        t_node *first = stack->top;
        t_node *second = stack->top->next;
        first->next = second->next;
        second->next = first;
        stack->top = second;
    }
}

void sa(t_stack *stack)
{
    ft_sa(stack);
    print("sa\n");
}

void ft_sb(t_stack *stack)
{
    if (stack->top && stack->top->next) {
        t_node *first = stack->top;
        t_node *second = stack->top->next;
        first->next = second->next;
        second->next = first;
        stack->top = second;
    }
}

void sb(t_stack *stack)
{
    ft_sb(stack);
    print("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    print("ss\n");
}

