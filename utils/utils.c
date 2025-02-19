/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:36:38 by asaracut          #+#    #+#             */
/*   Updated: 2025/02/19 03:00:48 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	ft_atoi(const char *str, t_stack *stack)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		n = n * 10 + (*str - '0');
		if ((n * sign) > INT_MAX || (n * sign) < INT_MIN)
			ft_exit("Nombre hors limites", stack);
		str++;
	}
	return ((int)(n * sign));
}