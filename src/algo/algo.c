/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:05:13 by asaracut          #+#    #+#             */
/*   Updated: 2025/04/23 17:07:21 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);
int		get_distance(t_stack *stack, int value);

int quick_short(t_stack *a, t_stack *b)
{
    // Vérification des cas de base
    if (is_sorted(a))
        return 0;
    
    // Optimisation: Taille des chunks réduite
    int chunk_size;
    if (a->size <= 100)
        chunk_size = 12;  // Réduit pour 100 nombres
    else
        chunk_size = 25;  // Optimisé pour 500 nombres
    
    // Calculer la valeur min et max pour les stratégies de tri
    int min_val = find_min(a);
    int max_val = find_max(a);
    int total_range = max_val - min_val + 1;
    
    // Étape 1: Stratégie de partition inspirée du code GitHub
    int mid_val = min_val + (total_range / 2);  // Valeur médiane
    
    // Première passe: pousser les éléments inférieurs à la médiane vers B
    int initial_size = a->size;
    for (int i = 0; i < initial_size; i++)
    {
        if (a->top->value <= mid_val)
        {
            pb(a, b);
            
            // Stratégie optimisée pour B: rotation si le nombre est petit
            if (b->size > 1 && b->top->value < (min_val + mid_val) / 2)
                rb(b);
        }
        else
        {
            // Si on a B et que le haut de B est petit, faire rotation double
            if (b->size > 1 && b->top->value < (min_val + mid_val) / 2)
                rr(a, b);
            else
                ra(a);
        }
    }
    
    // Ajuster les limites pour le reste du tri
    int current_max = mid_val;
    int current_min = min_val;
    mid_val = current_min + (current_max - current_min) / 2;
    
    // Traiter le reste des éléments avec une approche optimisée
    while (a->size > 0 || !is_sorted(a))
    {
        // Pousser les éléments depuis A vers B par chunks optimisés
        while (a->size > 0)
        {
            // Chercher l'élément le plus proche qui est dans la plage actuelle
            int best_pos = -1;
            int best_cost = a->size;
            
            for (int i = 0; i < a->size; i++)
            {
                t_node *current = a->top;
                for (int j = 0; j < i; j++)
                    current = current->next;
                
                // Si l'élément est dans la plage actuelle
                if (current->value <= current_max && current->value >= current_min)
                {
                    // Calculer le coût: distance du sommet
                    int cost = (i <= a->size/2) ? i : (a->size - i);
                    if (cost < best_cost)
                    {
                        best_cost = cost;
                        best_pos = i;
                    }
                }
            }
            
            // Si aucun élément dans cette plage, passer à la prochaine
            if (best_pos == -1)
                break;
            
            // Amener l'élément au sommet avec le minimum de rotations
            if (best_pos <= a->size / 2)
            {
                for (int i = 0; i < best_pos; i++)
                    ra(a);
            }
            else
            {
                for (int i = 0; i < a->size - best_pos; i++)
                    rra(a);
            }
            
            // Pousser vers B et optimiser la position dans B
            pb(a, b);
            
            // Si l'élément est petit, le faire descendre
            if (b->size > 1 && b->top->value < mid_val)
                rb(b);
        }
        
        // Ajuster les limites pour le prochain chunk
        current_min = current_max + 1;
        current_max = current_min + chunk_size - 1;
        if (current_max > max_val)
            current_max = max_val;
            
        // Si on a tout poussé vers B ou tout est trié, sortir de la boucle
        if (a->size == 0 || is_sorted(a))
            break;
    }
    
    // Étape 2: Stratégie optimisée pour repousser de B vers A
    while (b->size > 0)
    {
        // Trouver l'élément le plus grand dans B et sa position
        int max_in_b = find_max(b);
        int max_pos = find_position(b, max_in_b);
        
        // Calculer le chemin le plus court pour l'amener au sommet
        if (max_pos <= b->size / 2)
        {
            for (int i = 0; i < max_pos; i++)
                rb(b);
        }
        else
        {
            for (int i = 0; i < b->size - max_pos; i++)
                rrb(b);
        }
        
        // Pousser vers A
        pa(a, b);
    }
    
    return 0;
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
		}
		return;
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
	else
		quick_short(a, b);
}
