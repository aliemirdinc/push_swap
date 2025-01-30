/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:00 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 17:01:00 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_max_to_a(t_stack **a, t_stack **b)
{
	int	max;

	max = find_max(*b);
	while ((*b)->num != max)
	{
		if (distance_to_max(*b, max) > 0)
			op_rb(b, 0);
		else
			op_rrb(b, 0);
	}
	op_pa(a, b, 0);
}

static void	initialize_chunk_sort(t_stack *a, int size,
									int *chunk_size, int *current_max)
{
	int	chunk_count;
	int	*sorted;
	int	min;
	int	max;

	if (size == 0)
		return ;
	if (size <= 100)
		chunk_count = 3;
	else if (size > 100)
		chunk_count = 7;
	sorted = get_sorted_array(a);
	if (!sorted)
		return ;
	min = sorted[0];
	max = sorted[size - 1];
	*chunk_size = (max - min) / chunk_count + 1;
	*current_max = sorted[0 + *chunk_size - 1];
	free(sorted);
}

void	chunk_sort(t_stack **a, t_stack **b, int size)
{
	int	chunk_size;
	int	current_max;

	initialize_chunk_sort(*a, size, &chunk_size, &current_max);
	push_chunks_to_b(a, b, chunk_size, &current_max);
	while (*b)
		push_max_to_a(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		chunk_sort(a, b, size);
}
