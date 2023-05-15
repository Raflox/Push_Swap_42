/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:43 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/15 18:23:19 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FIXME: ATOI Overflow
// FIXME: check_args ./push_swap "3" "-3" " "

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack *temp2;
	long long 	cost;
	int 	idx1;
	int		idx2;

	// if ac > 2 -> check
	// if ac == 1 -> exit
	b = NULL;
	if (argc > 2)
	{
		a = get_stack(argc, argv);
		if (!a || checkdup(&a))
		{
			free_stack(&a);
			error();
		}
		if (!is_sorted(&a))
		{
			while (lst_size(a) > 3 && a)
			{
				if (a->nbr < lst_avg(&a))
					pb(&a, &b);
				else
					ra(&a);
			}
			sort(&a);
			temp2 = b;
			while (lst_size(b) > 0)
			{
				cost = LONG_MAX;
				temp2 = b;
				while (temp2)
				{
					temp2->bff = find_bff(&a, temp2->nbr);
					if (cost_control(&a, &b, temp2->nbr, temp2->bff) < cost)
					{
						cost = cost_control(&a, &b, temp2->nbr, temp2->bff);
						idx1 = find_pos(&a, temp2->bff);
						idx2 = find_pos(&b, temp2->nbr);
					}
					temp2 = temp2->next;
				}
				put_top_a(&a, idx1);
				put_top_b(&b, idx2);
				pa(&b, &a);
			}
			put_top_a(&a, find_pos(&a, lst_min(&a)));
		}	
	}
	else
		error();
	free_stack(&a);
}


