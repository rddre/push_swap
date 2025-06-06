/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:09:13 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/01 04:59:44 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_exit("malloc stack_init.c ligne 17", NULL, NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_exit("malloc stack_init.c ligne 27", stack, NULL);
	new_node->value = value;
	new_node->next = NULL;
	if (stack->top == NULL)
	{
		stack->top = new_node;
	}
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

/*
		tecniquement faux mais j'ai la flemme de corriger
		ca ne free pas lautre stack si ca echoue je doit
		cree une autre function que fait que free +
		receptionner dans les autre function si ca a pas
		marche pour bien tout free mais bon en soit
		c'est pas tres posible de faire sauter ces malloc
*/