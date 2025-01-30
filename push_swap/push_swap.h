/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:44:38 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/30 14:27:51 by aldinc           ###   ########.fr       */
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

typedef struct s_params
{
	int	rotations;
	int	size;
	int	*current_max;
	int	chunk_size;
}	t_params;

void	error_exit(void);
void	check_sorted(t_stack *stack_a, t_stack *stack_b);
void	apply_action(char *action, t_stack **stack_a, t_stack **stack_b);
void	process_actions(t_stack **stack_a, t_stack **stack_b);
void	push_max_to_a(t_stack **a, t_stack **b);
int		find_max(t_stack *stack);
void	chunk_sort(t_stack **a, t_stack **b, int size);
void	sort_stack(t_stack **a, t_stack **b);
int		*get_sorted_array(t_stack *stack);
int		handle_error(char **inputs);
int		handle_repetition_error(long *numbers, char **inputs);
int		get_input_size(char **inputs);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		distance_to_min(t_stack *stack, int min);
int		distance_to_max(t_stack *stack, int max);
void	push_to_beginning(t_stack **stack, int min);
int		is_under_five(int argc, char **argv,
			t_stack **stack_a, t_stack **stack_b);
int		is_valid_input(char **inputs);
int		is_sorted(t_stack *stack);
int		is_there_repetition(long *array, int size);
char	**process_input(int argc, char **argv);
void	*convert_to_long(char **splitted_inputs, int *size);
t_stack	*make_it_stack(long *numbers, int size);
void	free_split(char **split);
void	op_sa(t_stack **a, int i);
void	op_sb(t_stack **b, int i);
void	op_ss(t_stack **a, t_stack **b, int i);
void	op_pa(t_stack **a, t_stack **b, int i);
void	op_pb(t_stack **b, t_stack **a, int i);
void	op_ra(t_stack **a, int i);
void	op_rb(t_stack **b, int i);
void	op_rr(t_stack **a, t_stack **b, int i);
void	op_rra(t_stack **a, int i);
void	op_rrb(t_stack **b, int i);
void	op_rrr(t_stack **a, t_stack **b, int i);
t_stack	*ft_lstlast2(t_stack *lst);
void	free_stack(t_stack *stack);
void	ft_error(char *message);
int		stack_size(t_stack *stack);
void	push_chunks_to_b(t_stack **a, t_stack **b,
			int chunk_size, int *current_max);

#endif
