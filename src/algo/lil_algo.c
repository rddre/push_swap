/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:12:58 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/01 04:55:26 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->next->value
		&& a->top->value > a->top->next->next->value)
	{
		sa(a);
	}
	if (a->top->next->value > a->top->next->next->value)
	{
		sa(a);
	}
	if (a->top->value > a->top->next->value)
	{
		ra(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	distance;

	if (is_sorted(a))
		return ;
	distance = get_distance(a, find_min(a));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	distance;

	if (is_sorted(a))
		return ;
	distance = get_distance(a, find_min(a));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
