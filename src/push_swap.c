/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:24:36 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/26 01:08:02 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int nb_arg, char **arg)
{
    if (nb_arg == 1)
        return(print("erreur : pas d'argument"));
    print(arg[1]);
    return (1);
}
