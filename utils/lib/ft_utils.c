/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:05:41 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/15 18:11:58 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	mod_atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	if (str[i] == '-' && ++i)
		sign = -sign;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error();
		res = res * 10 + str[i] - 48;
		i++;
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		error();
	return (res * sign);
}

// Function to find position on stack
int	find_pos(t_stack **stack, int nbr)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->nbr == nbr)
		{
			temp->index = i;
			return (i);
		}
		temp = temp->next;
		i++;
	}
	return (0);
}

// Function to find each nbr bff
int	find_bff(t_stack **a, int nb)
{
	long int	bff;
	long int	counter;
	long int	tmp;
	t_stack		*temp;

	counter = LONG_MAX;
	temp = *a;
	while (temp)
	{
		tmp = (long int)(temp)->nbr - nb;
		if ((tmp < counter) && ((temp)->nbr > nb))
		{
			counter = tmp;
			bff = (temp)->nbr;
		}
		(temp) = (temp)->next;
	}
	return (bff);
}

// Function to calculate cost of moves
int	cost_control(t_stack **a, t_stack **b, int nbr, int bff)
{
	int	cost;

	cost = 0;
	if ((find_pos(b, nbr) <= lst_size(*b) / 2))
		cost += find_pos(b, nbr);
	else if (find_pos(b, nbr) > lst_size(*b) / 2)
		cost += lst_size(*b) - find_pos(b, nbr);
	if ((find_pos(a, bff)) <= lst_size(*a) / 2)
		cost += find_pos(a, bff);
	else if (find_pos(a, bff) >= lst_size(*a) / 2)
		cost += lst_size(*a) - find_pos(a, bff);
	(*b)->cost = cost;
	return (cost);
}

// Function to find the minimum number on stack
int	lst_min(t_stack **stack)
{
	t_stack	*temp;
	int		min;

	temp = *stack;
	min = temp->nbr;
	while (temp)
	{
		if (temp->nbr < min)
			min = temp->nbr;
		temp = temp->next;
	}
	return (min);
}
