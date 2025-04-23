/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:24:36 by asaracut          #+#    #+#             */
/*   Updated: 2025/04/18 22:58:36 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>
void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		printf("Stack vide\n");
		return ;
	}
	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

int main(int nb_arg, char **arg)
{
    if (nb_arg == 1)
	{
        return(print("erreur : pas d'argument"));
	}
	
	t_stack *a;
	t_stack *b;

	a = init_stack();
	if (!a)
    	ft_exit("Erreur d'allocation mémoire pour la pile A", NULL, NULL);
	b = init_stack();
	if (!b)
		ft_exit("Erreur d'allocation mémoire pour la pile B", a, NULL);

    parsing(nb_arg, arg, a);

	algo(a, b);

    //print_stack(a);
    ft_exit(NULL, a, b);
    return (1);
}
