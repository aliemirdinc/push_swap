/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:55:56 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/30 13:17:48 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**process_input(int argc, char **argv)
{
	int		i;
	char	**splitted;
	char	*together;
	char	*temp;

	i = 1;
	together = ft_strdup("");
	if (!together)
		return (NULL);
	while (i < argc)
	{
		temp = together;
		together = ft_strjoin(together, argv[i]);
		free(temp);
		if (i < argc - 1)
		{
			temp = together;
			together = ft_strjoin(together, " ");
			free(temp);
		}
		i++;
	}
	splitted = ft_split(together, ' ');
	return (free(together), splitted);
}

void	*convert_to_long(char **splitted_inputs, int *size)
{
	int		i;
	long	*numbers;
	long	num;

	i = 0;
	while (splitted_inputs[i])
		i++;
	*size = i;
	numbers = (long *)malloc(sizeof(long) * i);
	if (!numbers)
		return (NULL);
	i = 0;
	while (splitted_inputs[i])
	{
		num = ft_atoi(splitted_inputs[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_error("Error");
			free(numbers);
			return (NULL);
		}
		numbers[i] = num;
		i++;
	}
	return ((void *)numbers);
}

static t_stack	*append_node(t_stack *stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		free_stack(stack);
		return (NULL);
	}
	new_node->num = value;
	new_node->next = NULL;
	if (!stack)
		return (new_node);
	current = stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (stack);
}

t_stack	*make_it_stack(long *numbers, int size)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		stack = append_node(stack, numbers[i]);
		if (!stack)
			return (NULL);
		i++;
	}
	return (stack);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
