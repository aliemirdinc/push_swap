/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:53:32 by aldinc            #+#    #+#             */
/*   Updated: 2025/01/29 19:41:27 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	handle_overflow(long sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long	ft_atoi(const char *str)
{
	long	result;
	long	sign;
	long	prev_result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		prev_result = result;
		result = result * 10 + (*str - '0');
		if (result / 10 != prev_result)
			return (handle_overflow(sign));
		str++;
	}
	return (result * sign);
}
