/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:15:30 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 14:15:30 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*initialize_stack(int argc, char **argv)
{
	char	**inputs;
	long	*numbers;
	t_stack	*stack;
	int		size;

	inputs = process_input(argc, argv);
	numbers = convert_to_long(inputs, &size);
	stack = make_it_stack(numbers, size);
	if (argc < 2)
		return (NULL);
	if (!inputs || !is_valid_input(inputs))
		error_exit();
	if (!numbers)
		error_exit();
	free_split(inputs);
	free(numbers);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = initialize_stack(argc, argv);
	process_actions(&stack_a, &stack_b);
	check_sorted(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
