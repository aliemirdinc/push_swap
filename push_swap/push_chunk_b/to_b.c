/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:56:56 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 13:56:56 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	should_move_to_b(int top_num,
							int current_max)
{
	int	re;

	if (top_num <= current_max)
		re = 1;
	else
		re = 0;
	return (re);
}

static void	handle_b_rotation(t_stack **b, int top_num,
								int current_max, int chunk_size)
{
	if (top_num < current_max - chunk_size / 2)
	{
		op_rb(b, 0);
	}
}

static void	rotate_a_or_update_max(t_stack **a, t_params *params)
{
	op_ra(a, 0);
	params->rotations++;
	if (params->rotations >= params->size)
	{
		*(params->current_max) += params->chunk_size;
		params->rotations = 0;
	}
}

void	push_chunks_to_b(t_stack **a, t_stack **b,
							int chunk_size, int *current_max)
{
	t_params	params;
	int			top_num;

	params.rotations = 0;
	params.chunk_size = chunk_size;
	params.current_max = current_max;
	while (*a)
	{
		params.size = stack_size(*a);
		top_num = (*a)->num;
		if (should_move_to_b(top_num, *current_max))
		{
			op_pb(b, a, 0);
			handle_b_rotation(b, top_num, *current_max, chunk_size);
		}
		else
		{
			rotate_a_or_update_max(a, &params);
		}
		if (!(*a))
			break ;
	}
}
