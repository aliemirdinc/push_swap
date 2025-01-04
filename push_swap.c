/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:22:07 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/04 23:07:56 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_nums;
	int		*numbers;

	if (argc < 2)
		return (0);
	split_nums = process_input(argc, argv);
	if (!split_nums)
		return (1);
	numbers = convert_to_int(split_nums);
	free_split(split_nums); // Free string array after conversion
	if (!numbers)
		return (1);
	// Run algorithm here
	free(numbers);// Free after algorithm completes
	return (0);
}
