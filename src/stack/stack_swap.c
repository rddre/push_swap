/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 05:18:36 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/01 04:57:58 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->top && stack->top->next)
	{
		first = stack->top;
		second = stack->top->next;
		first->next = second->next;
		second->next = first;
		stack->top = second;
	}
}

void	sa(t_stack *stack)
{
	ft_sa(stack);
	print("sa\n");
}

void	ft_sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->top && stack->top->next)
	{
		first = stack->top;
		second = stack->top->next;
		first->next = second->next;
		second->next = first;
		stack->top = second;
	}
}

void	sb(t_stack *stack)
{
	ft_sb(stack);
	print("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	print("ss\n");
}
