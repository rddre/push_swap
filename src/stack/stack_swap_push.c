/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 05:18:36 by asaracut          #+#    #+#             */
/*   Updated: 2025/02/19 05:20:12 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void sa(t_stack *stack)
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
    if (stack->top && stack->top->next) {
        t_node *first = stack->top;
        t_node *second = stack->top->next;
        first->next = second->next;
        second->next = first;
        stack->top = second;
    }
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->top) {
        t_node *tmp = stack_b->top;
        stack_b->top = tmp->next;
        tmp->next = stack_a->top;
        stack_a->top = tmp;
        stack_a->size++;
        stack_b->size--;
    }
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top) {
        t_node *tmp = stack_a->top;
        stack_a->top = tmp->next;
        tmp->next = stack_b->top;
        stack_b->top = tmp;
        stack_a->size--;
        stack_b->size++;
    }
}