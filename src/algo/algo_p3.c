/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 04:41:49 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/03 04:43:56 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Calcule le coût pour atteindre une position et vérifie s'il est optimal */
int	check_posi_cost(int pos, int stack_size, int *best_cost, int *best_pos)
{
	int	cost;

	if (pos <= stack_size / 2)
		cost = pos;
	else
		cost = stack_size - pos;
	if (cost < *best_cost)
	{
		*best_cost = cost;
		*best_pos = pos;
	}
	return (cost);
}

/* Trouve la position optimale pour le prochain élément à déplacer */
int	find_best_position(t_stack *a, int current_min, int current_max)
{
	int		best_pos;
	int		best_cost;
	t_node	*current;
	int		i;
	int		cost;

	best_pos = -1;
	best_cost = a->size;
	current = a->top;
	i = 0;
	while (i < a->size)
	{
		if (current->value <= current_max && current->value >= current_min)
		{
			cost = check_posi_cost(i, a->size, &best_cost, &best_pos);
			if (cost <= 2)
				break ;
		}
		current = current->next;
		i++;
	}
	return (best_pos);
}

/* Déplace l'élément à la position donnée vers le sommet */
void	move_to_top(t_stack *a, int best_pos)
{
	int	i;

	if (best_pos <= a->size / 2)
	{
		i = 0;
		while (i < best_pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < a->size - best_pos)
		{
			rra(a);
			i++;
		}
	}
}

/* Déplace l'élément à la position donnée vers le sommet de la pile B */
void	move_to_top_b(t_stack *b, int pos)
{
	int	i;

	if (pos <= b->size / 2)
	{
		i = 0;
		while (i < pos)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < b->size - pos)
		{
			rrb(b);
			i++;
		}
	}
}

/* Traite un chunk et pousse les éléments vers B */
void	p_sin_chunk(t_stack *a, t_stack *b, int current_min,
		int current_max)
{
	int	best_pos;

	while (a->size > 0)
	{
		best_pos = find_best_position(a, current_min, current_max);
		if (best_pos == -1)
			break ;
		move_to_top(a, best_pos);
		pb(a, b);
		if (b->size > 1 && b->top->value < (current_min + (current_max
					- current_min) / 3))
			rb(b);
	}
}
