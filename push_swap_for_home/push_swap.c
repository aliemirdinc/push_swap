/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:22:07 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/03 20:06:31 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//kontroller kaldı

//algoritma kaldı

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	**splitted;
		char	*together;
		int		c = argc;
		int		i = 1;

		if (argc == 2)
			splitted = ft_split(argv[1], ' ');
		if ((argc > 2))
		{
			while ((c > 2))
			{
				together = ft_strjoin(argv[i], argv[i+1]);
				i++;
				c--;
			}
			splitted = ft_split(together, ' ');
		}
	}
}
