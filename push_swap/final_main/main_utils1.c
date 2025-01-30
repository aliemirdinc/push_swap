/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:58:40 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/28 16:58:40 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

int	*get_sorted_array(t_stack *stack)
{
	int		*arr;
	int		size;
	t_stack	*temp;
	int		i;

	size = stack_size(stack);
	arr = (int *)malloc(size * sizeof(int));
	temp = stack;
	i = 0;
	if (!arr)
		return (NULL);
	while (temp)
	{
		arr[i++] = temp->num;
		temp = temp->next;
	}
	quick_sort(arr, 0, size - 1);
	return (arr);
}
