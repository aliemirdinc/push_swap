/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:53:13 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/27 13:49:44 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_sa(t_stack **a, int i)
{
	int	buf;

	if (!(*a) || !((*a)->next))
		return ;
	else
	{
		buf = (*a)->num;
		(*a)->num = (*a)->next->num;
		(*a)->next->num = buf;
	}
	if (i == 0)
		ft_printf("sa\n");
}

void	op_sb(t_stack **b, int i)
{
	int	buf;

	if (!(*b) || !((*b)->next))
		return ;
	else
	{
		buf = (*b)->num;
		(*b)->num = (*b)->next->num;
		(*b)->next->num = buf;
	}
	if (i == 0)
		ft_printf("sb\n");
}

void	op_ss(t_stack **a, t_stack **b, int i)
{
	if (!(*a) || !(*b) || !((*a)->next) || !((*b)->next))
		return ;
	op_sa(a, i + 42);
	op_sb(b, i + 42);
	if (i == 0)
		ft_printf("ss\n");
}

void	op_pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if (!(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (i == 0)
		ft_printf("pa\n");
}

void	op_pb(t_stack **b, t_stack **a, int i)
{
	t_stack	*temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (i == 0)
		ft_printf("pb\n");
}
