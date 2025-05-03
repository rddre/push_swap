/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 04:41:25 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/03 04:42:52 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Initialise la taille des chunks selon la taille de la pile */
void	init_chunk_size(t_stack *a, int *chunk_size)
{
	*chunk_size = 0;
	if (a->size <= 100)
		*chunk_size = 14;
	else
		*chunk_size = 28;
}

/* Calcule les valeurs min, max et médiane pour le tri */
void	init_sort_values(t_stack *a, int *min_val, int *max_val, int *mid_val)
{
	int	total_range;

	if (is_sorted(a))
		return ;
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
