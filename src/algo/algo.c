/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:05:13 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/03 04:45:24 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Traite les éléments par chunks et les pousse vers B */
void	process_chunks(t_stack *a, t_stack *b, t_chunk_params params)
{
	int	current_min;
	int	current_max;

	current_max = params.min_val + (params.max_val - params.min_val) / 2;
	current_min = params.min_val;
	while (a->size > 0 || !is_sorted(a))
	{
		p_sin_chunk(a, b, current_min, current_max);
		current_min = current_max + 1;
		current_max = current_min + params.chunk_size - 1;
		if (current_max > params.max_val)
			current_max = params.max_val;
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
	int				min_val;
	int				max_val;
	int				mid_val;
	int				chunk_size;
	t_chunk_params	params;

	if (is_sorted(a))
		return (0);
	init_chunk_size(a, &chunk_size);
	init_sort_values(a, &min_val, &max_val, &mid_val);
	first_partition(a, b, min_val, mid_val);
	params.min_val = min_val;
	params.max_val = max_val;
	params.chunk_size = chunk_size;
	process_chunks(a, b, params);
	rebuild_stack(a, b);
	return (0);
}

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
	quick_short(a, b);
}
