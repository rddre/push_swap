/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:34:45 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/01 04:56:20 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Vérifie si la pile est déjà triée*/
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/* Trouve la plus petite valeur dans la pile*/
int	find_min(t_stack *stack)
{
	int		min;
	t_node	*current;

	if (!stack->top)
		return (0);
	min = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

/* Trouve la plus grande valeur dans la pile*/
int	find_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (!stack->top)
		return (0);
	max = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

/* Trouve la position d'une valeur dans la pile*/
int	find_position(t_stack *stack, int value)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

/* Trouve la distance/position d'une valeur dans la pile*/
int	get_distance(t_stack *stack, int value)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack->top;
	while (current && current->value != value)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}
