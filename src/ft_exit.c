/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:09:33 by asaracut          #+#    #+#             */
/*   Updated: 2025/02/19 04:48:29 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void free_list(t_node *list)
{
    t_node *tmp;
    
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void ft_exit(char *str, t_stack *stack)
{
    if (str)
    {
        print("Error: ");
        print(str);
        print("\n");
    }
    if (stack)
    {
        free_list(stack->top);
        stack->top = NULL;
        stack->size = 0;
    }
    exit(EXIT_FAILURE);
}