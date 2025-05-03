/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:36:46 by asaracut          #+#    #+#             */
/*   Updated: 2025/05/03 04:40:57 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}		t_stack;

/* Structure pour regrouper les paramètres des chunks */
typedef struct s_chunk_params
{
	int	min_val;
	int	max_val;
	int	chunk_size;
}		t_chunk_params;

/*            utils             */
int		print(char *s);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str, t_stack *stack);

/*          parsing             */
int		parsing(int nb_arg, char **arg, t_stack *stack);

/*             algo             */
void	algo(t_stack *a, t_stack *b);

/*          algo utils          */
int		is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);
int		get_distance(t_stack *stack, int value);
int		quick_short(t_stack *a, t_stack *b);

/*            lil algo           */
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);

/*            all function algo          */
void	init_chunk_size(t_stack *a, int *chunk_size);
void	init_sort_values(t_stack *a, int *min_val, int *max_val, int *mid_val);
void	organize_b_stack(t_stack *b, int value, int min_val, int mid_val);
void	first_partition(t_stack *a, t_stack *b, int min_val, int mid_val);
int		check_posi_cost(int pos, int stack_size, int *best_cost, int *best_pos);
int		find_best_position(t_stack *a, int current_min, int current_max);
void	move_to_top(t_stack *a, int best_pos);
void	move_to_top_b(t_stack *b, int pos);
void	p_sin_chunk(t_stack *a, t_stack *b, int current_min, int current_max);
void	process_chunks(t_stack *a, t_stack *b, t_chunk_params params);
void	rebuild_stack(t_stack *a, t_stack *b);

/*            stack            */
t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
/*        Swap actions          */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
/*         Push actions        */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
/*        Rotate actions       */
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
/*    Reverse rotate actions   */
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/*            free              */
void	ft_exit(char *str, t_stack *a, t_stack *b);

#endif