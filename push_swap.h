/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:02:27 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/04 23:15:18 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

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
char	**process_input(int argc, char **argv);
int		*convert_to_int(char **splitted_inputs);
void	free_split(char **split);

#endif
