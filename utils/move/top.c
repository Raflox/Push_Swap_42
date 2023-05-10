/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:57:37 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/10 16:50:27 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	put_top_a(t_stack **lst, int index)
{
	int	size;
	int	i;

	size = lst_size(*lst);
/* 	if (index == -1)
		return (-1); */
	if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			ra(lst);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			rra(lst);
			i++;
		}
	}
}

void	put_top_b(t_stack **lst, int index)
{
	int	size;
	int	i;

	size = lst_size(*lst);
/* 	if (index == -1)
		return (-1); */
	if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			rb(lst);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			rrb(lst);
			i++;
		}
	}
}
