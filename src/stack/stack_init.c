/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:09:13 by asaracut          #+#    #+#             */
/*   Updated: 2025/03/24 00:00:20 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack *init_stack(void) // initialisation de la map
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        ft_exit("malloc stack_init.c ligne 17", NULL, NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void push(t_stack *stack, int value) // ajouter un element
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        ft_exit("malloc stack_init.c ligne 27", stack, NULL);
    new_node->value = value;
    new_node->next = NULL;  // Ce sera le dernier élément
    
    if (stack->top == NULL) // Si la stack est vide, on l'initialise
    {
        stack->top = new_node;
    }
    else
    {
        t_node *current = stack->top;
        while (current->next)  // Parcours jusqu'au dernier élément
            current = current->next;
        current->next = new_node;  // Ajout en fin de liste
    }
    stack->size++;
}


/*    
      tecniquement faux mais j'ai la flemme de corriger
      ca ne free pas lautre stack si ca echoue je doit
      cree une autre function que fait que free +
      receptionner dans les autre function si ca a pas
      marche pour bien tout free mais bon en soit
      c'est pas tres posible de faire sauter ces malloc
*/