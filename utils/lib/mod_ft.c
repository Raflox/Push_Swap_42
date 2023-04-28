/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:05:41 by rafilipe          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:47 by rafilipe         ###   ########.fr       */
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
	while (str[i] && ft_isdigit(str[i]))
	{
		if (!ft_isdigit(str[i]))
			error();
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	lst_add(t_stack *lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL)
		lst = new;
	else
	{
		last = lst_last(lst);
		last -> next = new;
	}
}

t_stack	*lst_new(int content)
{
	t_stack			*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = content;
	new -> next = NULL;
	return (new);
}

t_stack	*lst_last(t_stack *lst)
{
	t_stack	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}


