/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:53:13 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/03 19:04:56 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack **a, int i)
{
	t_stack	*buf;

	buf = *a;
	if (!((*a)->next->next) || !(*a))
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

void	op_ss(t_stack **a, t_stack **b, int i)
{
	t_stack	buf_for_a;
	t_stack	buf_for_b;

	if (!((*a)->next) || !(*a) || !((*b)->next) || !(*b))
		return ;
	op_sa(a, i);
	op_sa(b, i);
	if (i == 0)
		ft_printf("sa\n");
}

void	op_pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*buf;

	if (!(*a) || !(*b))
		return ;
	ft_lstadd_front(a, *b);
	*b = (*b)->next;
	if (i == 0)
		ft_printf("pa\n");
}

void	op_pb(t_stack **b, t_stack **a, int i)
{
	t_stack	*buf;

	if (!(*b) || !(*a))
		return ;
	ft_lstadd_front(b, *a);
	*a = (*a)->next;
	if (i == 0)
		ft_printf("pb\n");
}

void	op_ra(t_stack **a, int i)
{
	t_stack	*buf;

	if (!(*a) || !((*a)->next))
		return ;
	buf = (*a);
	*a = ft_lstlast(*a);
	(*a)->next = buf;
	*a = buf->next;
	buf->next = NULL;
	if (i == 0)
		ft_printf("ra\n");
}
