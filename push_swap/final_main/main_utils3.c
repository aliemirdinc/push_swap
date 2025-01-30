/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:17:55 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 17:17:55 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	handle_error(char **inputs)
{
	free_split(inputs);
	ft_error("Error");
	return (1);
}

int	handle_repetition_error(long *numbers, char **inputs)
{
	free_split(inputs);
	free(numbers);
	ft_error("Error");
	return (1);
}

int	get_input_size(char **inputs)
{
	int	size;

	size = 0;
	while (inputs[size])
		size++;
	return (size);
}

static int	handle_sorting(int size, t_stack **stack_a, t_stack **stack_b)
{
	if (size == 2)
	{
		sort_two(stack_a);
		return (1);
	}
	if (size == 3)
	{
		sort_three(stack_a);
		return (1);
	}
	if (size == 4)
	{
		sort_four(stack_a, stack_b);
		return (1);
	}
	if (size == 5)
	{
		sort_five(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	is_under_five(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	char	**inputs;
	int		size;
	int		result;

	inputs = process_input(argc, argv);
	size = get_input_size(inputs);
	result = handle_sorting(size, stack_a, stack_b);
	free_split(inputs);
	return (result);
}
