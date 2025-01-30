/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:04:16 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 17:04:16 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (stack_a && stack_a->next)
	{
		if (stack_a->num > stack_a->next->num)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
}

void	apply_action(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(action, "sa\n") == 0)
		op_sa(stack_a, 1);
	else if (ft_strncmp(action, "sb\n") == 0)
		op_sb(stack_b, 1);
	else if (ft_strncmp(action, "ss\n") == 0)
		op_ss(stack_a, stack_b, 1);
	else if (ft_strncmp(action, "pa\n") == 0)
		op_pa(stack_a, stack_b, 1);
	else if (ft_strncmp(action, "pb\n") == 0)
		op_pb(stack_b, stack_a, 1);
	else if (ft_strncmp(action, "ra\n") == 0)
		op_ra(stack_a, 1);
	else if (ft_strncmp(action, "rb\n") == 0)
		op_rb(stack_b, 1);
	else if (ft_strncmp(action, "rr\n") == 0)
		op_rr(stack_a, stack_b, 1);
	else if (ft_strncmp(action, "rra\n") == 0)
		op_rra(stack_a, 1);
	else if (ft_strncmp(action, "rrb\n") == 0)
		op_rrb(stack_b, 1);
	else if (ft_strncmp(action, "rrr\n") == 0)
		op_rrr(stack_a, stack_b, 1);
	else
		error_exit();
}

void	process_actions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		apply_action(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
}
