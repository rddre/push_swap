/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 06:13:57 by asaracut          #+#    #+#             */
/*   Updated: 2025/03/05 20:40:44 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_valid_number(char *str, t_stack *stack)
{
	int i = 0;

	if (!str || !str[0])
		ft_exit("chaine de caractere vide ou nulle", stack, NULL);
	if (str[0] == '-' && str[1] != '\0')
		i++; 

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit("Caractere non conforme", stack, NULL);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == num)
			ft_exit("nombre doublon", stack, NULL);
		current = current->next;
	}
	return (0);
}

void	check_arg(char *arg, t_stack *stack)
{
	int		num;
	char	*token;
	char	*start;
	char	temp;

	token = arg;
	while (*token)
	{
		while (*token == ' ')
			token++;
		if (*token == '\0')
			break;
		start = token;
		while (*token && *token != ' ')
			token++;
		temp = *token;
		*token = '\0';
		if (is_valid_number(start, stack))
		{
			num = ft_atoi(start, stack);
			is_duplicate(stack, num);
			push(stack, num);
		}
		*token = temp;
	}
}

void	check_args(int nb_arg, char **arg, t_stack *stack)
{
	int	i;
	int	num;

	i = 1;
	while (i < nb_arg)
	{
		if (is_valid_number(arg[i], stack))
		{
			num = ft_atoi(arg[i], stack);
			is_duplicate(stack, num);
			push(stack, num);
		}
		i++;
	}
}

int	parsing(int nb_arg, char **arg, t_stack *stack)
{
	if (nb_arg == 2)
		check_arg(arg[1], stack);
	else
		check_args(nb_arg, arg, stack);
	return (1);
}
