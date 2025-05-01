/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:46:01 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/01 05:07:34 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_b->top)
	{
		tmp = stack_b->top;
		stack_b->top = tmp->next;
		tmp->next = stack_a->top;
		stack_a->top = tmp;
		stack_a->size++;
		stack_b->size--;
	}
	print("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_a->top)
	{
		tmp = stack_a->top;
		stack_a->top = tmp->next;
		tmp->next = stack_b->top;
		stack_b->top = tmp;
		stack_a->size--;
		stack_b->size++;
	}
	print("pb\n");
}
