/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:36:46 by asaracut          #+#    #+#             */
/*   Updated: 2025/03/04 12:15:01 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;    // Pointeur vers le prochain élément
} t_node;

typedef struct s_stack
{
    t_node  *top;    // Sommet de la pile | premier élément
    int     size;    // Taille actuelle de la pile
} t_stack;

/*            utils             */
int		print(char *s);
size_t	ft_strlen(const char *str);
int     ft_atoi(const char *str, t_stack *stack);

/*          parsing             */
int     parsing(int nb_arg, char **arg, t_stack *stack);

/*             algo             */
void algo(t_stack *a, t_stack *b);

/*            stack            */
t_stack *init_stack(void);
void    push(t_stack *stack, int value);
/*        Swap actions          */
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *stack_a, t_stack *stack_b);
/*         Push actions        */
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
/*        Rotate actions       */
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *stack_a, t_stack *stack_b);
/*    Reverse rotate actions   */
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *stack_a, t_stack *stack_b);

/*            free              */
void ft_exit(char *str, t_stack *a, t_stack *b);

#endif