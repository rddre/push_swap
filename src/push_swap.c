/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:24:36 by asaracut          #+#    #+#             */
/*   Updated: 2025/02/19 04:30:46 by asaracut         ###   ########.fr       */
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
        return(print("erreur : pas d'argument"));
    
    t_stack *stack;

    stack = init_stack();
    if (!stack)
        ft_exit("Erreur d'allocation mémoire", NULL);

    parsing(nb_arg, arg, stack);

    print_stack(stack);
    
    return (1);
}
