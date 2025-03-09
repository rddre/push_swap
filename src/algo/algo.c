/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:05:13 by asaracut          #+#    #+#             */
/*   Updated: 2025/03/05 23:35:29 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*///////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// Calcule un pivot à partir de la pile 'a'.
// Ici, nous utilisons la moyenne des valeurs comme pivot (pour simplifier).
int get_pivot(t_stack *a)
{
    int sum = 0;
    int count = 0;
    t_node *current = a->top;
    
    while (current)
    {
        sum += current->value;
        count++;
        current = current->next;
    }
    if (count == 0)
        return (0);
    return (sum / count);
}

// Fonction qui trie une pile de 3 éléments (déjà implémentée ou simplifiée)
void sort_three(t_stack *a)
{
    // Si la pile est déjà triée, on ne fait rien
    if (a->top->value < a->top->next->value &&
        a->top->next->value < a->top->next->next->value)
        return;
        
    // Exemple simple (peut être ajusté selon les cas)
    if (a->top->value > a->top->next->value)
    {
        sa(a);
        printf("sa\n");
    }
    if (a->top->next->value > a->top->next->next->value)
    {
        sa(a);
        printf("sa\n");
    }
    if (a->top->value > a->top->next->value)
    {
        ra(a);
        printf("ra\n");
    }
}

// Algorithme Quick Sort simplifié pour push_swap
void quick_sort(t_stack *a, t_stack *b)
{
    int pivot;
    int size_a;
    int i;

    // Cas de base : pour 1, 2 ou 3 éléments, on utilise des fonctions de tri simples.
    if (a->size <= 3)
    {
        if (a->size == 2)
        {
            if (a->top->value > a->top->next->value)
            {
                sa(a);
                printf("sa\n");
            }
        }
        else if (a->size == 3)
            sort_three(a);
        return;
    }
    
    // Pour plus de 3 éléments : partitionner la pile A en fonction d'un pivot.
    pivot = get_pivot(a);
    size_a = a->size;
    i = 0;
    while (i < size_a)
    {
        // Si l'élément en haut est inférieur au pivot, on le pousse dans B.
        if (a->top->value < pivot)
        {
            pb(a, b);
            printf("pb\n");
        }
        else
        {
            // Sinon, on fait une rotation pour mettre l'élément en bas.
            ra(a);
            printf("ra\n");
        }
        i++;
    }
    
    // On trie récursivement la pile A (les éléments supérieurs ou égaux au pivot).
    quick_sort(a, b);
    
    // Une fois A triée, on remet les éléments de B dans A.
    while (b->size > 0)
    {
        pa(a, b);
        printf("pa\n");
    }
}

///////////////////////////////////////*/

void sort_three(t_stack *a)
{
    if (a->top->value > a->top->next->value && a->top->value > a->top->next->next->value) 
    {
        sa(a);
        print("sa\n");
    }
    if (a->top->next->value > a->top->next->next->value) 
    {
        sa(a);
        print("sa\n");
    }
    if (a->top->value > a->top->next->value)
    {
        ra(a);
        print("ra\n");
    }
}

void algo(t_stack *a, t_stack *b)
{
    (void)b;
    if (a->size == 1)
        return ;
    else if (a->size == 2)
    {
        if (a->top->value > a->top->next->value)
        {
            sa(a);
            print("sa\n");
        }
        return;
    }
    else if (a->size == 3)
    {
        sort_three(a);
        return ;
    }
    print("pas encore fini\n");
}
