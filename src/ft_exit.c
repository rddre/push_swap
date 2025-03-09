/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:09:33 by asaracut          #+#    #+#             */
/*   Updated: 2025/03/04 12:06:03 by asaracut         ###   ########.fr       */
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

void ft_exit(char *str, t_stack *a, t_stack *b)
{
    if (str)
    {
        print("Error: ");
        print(str);
        print("\n");
    }
    if (a)
    {
        free_list(a->top);
        free(a);
    }
    if (b)
    {
        free_list(b->top);
        free(b);
    }
    exit(EXIT_FAILURE);
}
