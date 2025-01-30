/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:39 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 12:28:39 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	op_sa(stack, 0);
}

static void	do_sa_rra(t_stack **stack)
{
	op_sa(stack, 0);
	op_rra(stack, 0);
}

void	sort_three(t_stack **stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack)->num;
	num2 = (*stack)->next->num;
	num3 = (*stack)->next->next->num;
	if (is_sorted(*stack) == 1)
		return ;
	if (num1 > num2 && num2 > num3)
		do_sa_rra(stack);
	if (num2 < num3 && num3 < num1)
		op_ra(stack, 0);
	if (num3 < num1 && num1 < num2)
	{
		op_sa(stack, 0);
		op_ra(stack, 0);
	}
	if (num2 < num1 && num1 < num3)
		op_sa(stack, 0);
	if (num1 < num3 && num3 < num2)
	{
		op_sa(stack, 0);
		op_ra(stack, 0);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	if (is_sorted(*a) == 1)
		return ;
	min = find_min(*a);
	push_to_beginning(&(*a), min);
	if ((*a)->num == min)
	{
		op_pb(b, a, 0);
		sort_three(a);
		op_pa(a, b, 0);
		return ;
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;

	if (is_sorted(*a) == 1)
		return ;
	min = find_min(*a);
	push_to_beginning(a, min);
	if ((*a)->num == min)
	{
		op_pb(b, a, 0);
		sort_four(a, b);
		op_pa(a, b, 0);
		return ;
	}
}
