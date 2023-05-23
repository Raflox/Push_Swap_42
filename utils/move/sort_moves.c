/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:48:37 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 16:23:38 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	pre_sort(t_stack **a, t_stack **b)
{
	while (lst_size(*a) > 3 && a)
	{
		if ((*a)->nbr < lst_avg(a))
			pb(a, b);
		else
			ra(a);
	}
	sort(a);
}

static void	sort_algo(t_stack **a, t_stack **b)
{
	t_stack		*temp2;
	long long	cost;
	int			idx1;
	int			idx2;

	cost = LONG_MAX;
	temp2 = *b;
	while (temp2)
	{
		temp2->bff = find_bff(a, temp2->nbr);
		if (cost_control(a, b, temp2->nbr, temp2->bff) < cost)
		{
			cost = cost_control(a, b, temp2->nbr, temp2->bff);
			idx1 = find_pos(a, temp2->bff);
			idx2 = find_pos(b, temp2->nbr);
		}
		temp2 = temp2->next;
	}
	put_top_a(a, idx1);
	put_top_b(b, idx2);
	pa(b, a);
}

void	sort_moves(t_stack *a, t_stack *b)
{
	if (!is_sorted(&a))
	{
		pre_sort(&a, &b);
		while (lst_size(b) > 0)
		{
			sort_algo(&a, &b);
		}
		put_top_a(&a, find_pos(&a, lst_min(&a)));
	}
}
