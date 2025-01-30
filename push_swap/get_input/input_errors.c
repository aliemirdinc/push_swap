/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:27:55 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 12:27:55 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_input(char **inputs)
{
	int	i;
	int	j;

	i = 0;
	while (inputs[i])
	{
		j = 0;
		if (inputs[i][j] == '-' || inputs[i][j] == '+')
			j++;
		if (!inputs[i][j])
			return (0);
		while (inputs[i][j])
		{
			if (!ft_isdigit(inputs[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_there_repetition(long *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
