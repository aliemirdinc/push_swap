/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:55:56 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/04 23:05:54 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//splits the input into an array of strings
char	**process_input(int argc, char **argv)
{
	int		i;
	char	**splitted;
	char	*together;
	char	*temp;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	together = ft_strdup(argv[1]);
	i = 2;
	while (i++ < argc)
	{
		temp = together;
		together = ft_strjoin(temp, " ");
		free(temp);
		temp = together;
		together = ft_strjoin(temp, argv[i]);
		free(temp);
	}
	splitted = ft_split(together, ' ');
	free(together);
	return (splitted);
}

//changes the string to the integer
int	*convert_to_int(char **splitted_inputs)
{
	int	i;
	int	*numbers;

	i = 0;
	while (splitted_inputs[i])
		i++;
	numbers = (int *)malloc(sizeof(int) * i);
	if (!numbers)
		return (NULL);
	i = 0;
	while (splitted_inputs[i])
	{
		numbers[i] = ft_atoi(splitted_inputs[i]);
		i++;
	}
	return (numbers);
}

//frees the split array of strings
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
