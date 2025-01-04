/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:25:58 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/03 19:11:06 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rb(t_stack **b, int i)
{
	t_stack	*buf;

	if (!(*b) || !((*b)->next))
		return ;
	buf = (*b);
	*b = ft_lstlast(*b);
	(*b)->next = buf;
	*b = buf->next;
	buf->next = NULL;
	if (i == 0)
		ft_printf("rb\n");
}

void	op_rr(t_stack **a, t_stack **b, int i)
{
	if (!(*a) || !((*a)->next) || !(*b) || !((*b)->next))
		return ;
	op_ra(a, i - 42);
	op_rb(b, i - 42);
	if (i == 0)
		ft_printf("rr\n");
}

void	op_rra(t_stack **a, int i)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (!(*a) || !((*a)->next))
		return ;
	prev_last = *a;
	while (prev_last->next && prev_last->next->next)
		prev_last = prev_last->next;
	last = prev_last->next;
	last->next = *a;
	*a = last;
	prev_last->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	op_rrb(t_stack **b, int i)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (!(*b) || !((*b)->next))
		return ;
	prev_last = *b;
	while (prev_last->next && prev_last->next->next)
		prev_last = prev_last->next;
	last = prev_last->next;
	last->next = *b;
	*b = last;
	prev_last->next = NULL;
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	op_rrr(t_stack **a, t_stack **b, int i)
{
	if (!(*a) || !((*a)->next) || !(*b) || !((*b)->next))
		return ;
	op_ra(a, i - 42);
	op_rb(b, i - 42);
	if (i == 0)
		ft_printf("rrr\n");
}
