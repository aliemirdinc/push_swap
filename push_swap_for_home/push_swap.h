/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:02:27 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/03 19:12:09 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "libft/libft.h"

typedef struct s_stack
{
    int num;
    struct s_stack *next;
}   t_stack;

void	op_sa(t_stack **a, int i);
void	op_ss(t_stack **a, t_stack **b, int i);
void	op_pa(t_stack **a, t_stack **b, int i);
void	op_pb(t_stack **b, t_stack **a, int i);
void	op_ra(t_stack **a, int i);
void	op_rb(t_stack **b, int i);
void	op_rr(t_stack **a, t_stack **b, int i);
void	op_rra(t_stack **a, int i);
void	op_rrb(t_stack **b, int i);
void	op_rrr(t_stack **a, t_stack **b, int i);

#endif
