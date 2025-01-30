/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:29 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 12:28:29 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	handle_initialization(int argc, char **argv,
									t_stack **a, t_stack **b)
{
	char	**inputs;
	long	*numbers;
	int		size;

	if (argc < 2)
		return (0);
	inputs = process_input(argc, argv);
	if (!is_valid_input(inputs))
		return (handle_error(inputs));
	numbers = convert_to_long(inputs, &size);
	if (!numbers)
		return (handle_error(inputs));
	if (is_there_repetition(numbers, size))
		return (handle_repetition_error(numbers, inputs));
	free_split(inputs);
	*a = make_it_stack(numbers, size);
	free(numbers);
	*b = NULL;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!handle_initialization(argc, argv, &a, &b))
		return (0);
	if (is_under_five(argc, argv, &a, &b) == 1)
		return (0);
	sort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
