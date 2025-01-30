/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:25:58 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/27 13:49:44 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_ra(t_stack **a, int i)
{
	t_stack	*head;
	t_stack	*last;

	if (!(*a) || !((*a)->next))
		return ;
	head = *a;
	last = ft_lstlast2(*a);
	*a = (*a)->next;
	last->next = head;
	head->next = NULL;
	if (i == 0)
		ft_printf("ra\n");
}

void	op_rb(t_stack **b, int i)
{
	t_stack	*head;
	t_stack	*last;

	if (!(*b) || !((*b)->next))
		return ;
	head = *b;
	last = ft_lstlast2(*b);
	*b = (*b)->next;
	last->next = head;
	head->next = NULL;
	if (i == 0)
		ft_printf("rb\n");
}

void	op_rr(t_stack **a, t_stack **b, int i)
{
	if (!(*a) || !((*a)->next) || !(*b) || !((*b)->next))
		return ;
	op_ra(a, i + 42);
	op_rb(b, i + 42);
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
		ft_printf("rra\n");
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
