/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:05:49 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/08 15:34:58 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_3(t_stack **a, t_count *counter)
{
	int		first;
	int		second;
	int		third;

	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;
	if ((first > second) && (second < third) && (first < third))
		sa(a, counter);
	else if ((first > second) && (second > third) && (first > third))
	{
		sa(a, counter);
		rra(a, counter);
	}
	else if ((first > second) && (second < third) && (first > third))
		ra(a, counter);
	else if ((first < second) && (second > third) && (first < third))
	{
		sa(a, counter);
		ra(a, counter);
	}	
	else if ((first < second) && (second > third) && (first > third))
		rra(a, counter);
}

void	sort(t_stack **a, t_count *counter)
{
	if (lst_size(*a) == 2 && !is_sorted(a))
		sa(a, counter);
	else if (lst_size(*a) == 3)
		sort_3(a, counter);
}

