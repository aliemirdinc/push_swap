/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:15:14 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 17:15:14 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	distance_to_min(t_stack *stack, int min)
{
	int	i;
	int	len;

	i = 0;
	len = stack_size(stack);
	if (stack->num == min)
		return (i);
	while (stack->num != min)
	{
		stack = stack->next;
		i++;
	}
	if (i > len / 2)
	{
		i = i - len;
	}
	return (i);
}

int	distance_to_max(t_stack *stack, int max)
{
	int	i;
	int	len;

	i = 0;
	len = stack_size(stack);
	if (stack->num == max)
		return (i);
	while (stack->num != max)
	{
		stack = stack->next;
		i++;
	}
	if (i > len / 2)
	{
		i = i - len;
	}
	return (i);
}

void	push_to_beginning(t_stack **stack, int min)
{
	int	distance;
	int	len;

	min = find_min(*stack);
	len = stack_size(*stack);
	distance = distance_to_min(*stack, min);
	if (distance >= 0)
	{
		while (distance-- > 0)
			op_ra(stack, 0);
	}
	else
	{
		while (distance++ < 0)
			op_rra(stack, 0);
	}
}
