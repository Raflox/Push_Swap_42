/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:05:41 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/08 12:27:06 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	mod_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error();
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

// function to calculate avg on stack
int	lst_avg(t_stack **a)
{
	int	avg;
	int i;

	i = 0;
	avg = 0;
	while (*a)
	{
		avg += (*a)->nbr;
		*a = (*a)->next;
		i++;
	}
	avg = avg / i;
	return (avg);
}
