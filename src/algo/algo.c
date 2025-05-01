/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:05:13 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/01 05:12:12 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Vérifie les cas de base et prépare les valeurs pour le tri */
void	init_quick_sort(t_stack *a, int *min_val, int *max_val, int *mid_val,
		int *chunk_size)
{
	int	total_range;

	if (is_sorted(a))
		return ;
	*chunk_size = 0;
	if (a->size <= 100)
		*chunk_size = 14;
	else
		*chunk_size = 28;
	*min_val = find_min(a);
	*max_val = find_max(a);
	total_range = *max_val - *min_val + 1;
	*mid_val = *min_val + (total_range / 2);
}

/* Gère la rotation de B en fonction des segments */
void	organize_b_stack(t_stack *b, int value, int min_val, int mid_val)
{
	int	segment_1;
	int	segment_2;

	segment_1 = min_val + (mid_val - min_val) / 3;
	segment_2 = min_val + 2 * (mid_val - min_val) / 3;
	if (b->size > 1 && value < segment_1)
		rb(b);
	else if (b->size > 1 && value < segment_2 && b->size > 10)
		rb(b);
}

/* Première phase: partition autour de la médiane */
void	first_partition(t_stack *a, t_stack *b, int min_val, int mid_val)
{
	int	initial_size;
	int	i;

	initial_size = a->size;
	i = 0;
	while (i < initial_size && a->size > 0)
	{
		if (a->top->value <= mid_val)
		{
			pb(a, b);
			organize_b_stack(b, b->top->value, min_val, mid_val);
		}
		else
		{
			if (b->size > 1 && b->top->value < (min_val + mid_val) / 2)
				rr(a, b);
			else
				ra(a);
		}
		if (i > initial_size * 1.2)
			break ;
		i++;
	}
}

/* Calcule le coût pour atteindre une position et vérifie s'il est optimal */
int	check_position_cost(int pos, int stack_size, int *best_cost, int *best_pos)
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
			cost = check_position_cost(i, a->size, &best_cost, &best_pos);
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
void	process_single_chunk(t_stack *a, t_stack *b, int current_min,
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

/* Traite les éléments par chunks et les pousse vers B */
void	process_chunks(t_stack *a, t_stack *b, int min_val, int max_val,
		int chunk_size)
{
	int	current_min;
	int	current_max;

	current_max = min_val + (max_val - min_val) / 2;
	current_min = min_val;
	while (a->size > 0 || !is_sorted(a))
	{
		process_single_chunk(a, b, current_min, current_max);
		current_min = current_max + 1;
		current_max = current_min + chunk_size - 1;
		if (current_max > max_val)
			current_max = max_val;
		if (a->size == 0 || is_sorted(a))
			break ;
	}
}

/* Reconstruction finale de A à partir de B */
void	rebuild_stack(t_stack *a, t_stack *b)
{
	int	max_in_b;
	int	max_pos;

	while (b->size > 0)
	{
		max_in_b = find_max(b);
		max_pos = find_position(b, max_in_b);
		move_to_top_b(b, max_pos);
		pa(a, b);
	}
}

/* Algorithme principal de tri rapide */
int	quick_short(t_stack *a, t_stack *b)
{
	int	min_val;
	int	max_val;
	int	mid_val;
	int	chunk_size;

	if (is_sorted(a))
		return (0);
	init_quick_sort(a, &min_val, &max_val, &mid_val, &chunk_size);
	first_partition(a, b, min_val, mid_val);
	process_chunks(a, b, min_val, max_val, chunk_size);
	rebuild_stack(a, b);
	return (0);
}

/* Fonction principale qui dirige le tri selon la taille de l'entrée */
void	algo(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size == 1)
		return ;
	else if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	else if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	else if (a->size == 4)
	{
		sort_four(a, b);
		return ;
	}
	else if (a->size == 5)
	{
		sort_five(a, b);
		return ;
	}
	else
		quick_short(a, b);
}
