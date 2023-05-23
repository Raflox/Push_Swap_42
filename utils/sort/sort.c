/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:05:49 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/15 23:08:27 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_3(t_stack **a)
{
	int		first;
	int		second;
	int		third;

	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;
	if ((first > second) && (second < third) && (first < third))
		sa(a);
	else if ((first > second) && (second > third) && (first > third))
	{
		sa(a);
		rra(a);
	}
	else if ((first > second) && (second < third) && (first > third))
		ra(a);
	else if ((first < second) && (second > third) && (first < third))
	{
		sa(a);
		ra(a);
	}	
	else if ((first < second) && (second > third) && (first > third))
		rra(a);
}

void	sort(t_stack **a)
{
	if (lst_size(*a) == 2 && !is_sorted(a))
		sa(a);
	else if (lst_size(*a) == 3)
		sort_3(a);
}
