/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:43 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/10 11:25:14 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_count	*init_count(void)
{
	t_count	*new;

	new = malloc(sizeof(t_count));
	new->moves = 0;
	return (new);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack *temp1;
	t_stack *temp2;
	t_count	*counter;
	long long 	cost;
	int 	idx1;
	int		idx2;

	// if ac == 2 -> split and check
	// if ac > 2 -> check
	// if ac == 1 -> exit

	a = NULL;
	b = NULL;
	idx1 = -1;
	idx2 = -1;
	counter = init_count();
	
	if (argc > 2)
	{
		a = get_stack(argc, argv);
		if (!a || checkdup(&a))
		{
			printf("DUP\n");
			free_stack(&a);
			error();
		}
		if (!is_sorted(&a))
		{
			while (lst_size(a) > 3 && a)
			{
				if (((*a).nbr) < lst_avg(&a))
					pb(&a, &b, counter);
				else
					ra(&a, counter);
			}
			sort(&a, counter);
			cost = __LONG_LONG_MAX__;
			temp2 = b;
			while (lst_size(b) > 0)
			{
				cost = __LONG_LONG_MAX__;
				temp2 = b;
				while (temp2)
				{
					temp2->bff = find_bff(&a, temp2->nbr);
					if (cost_control(&a, &b, temp2->nbr, temp2->bff) < cost)
					{
						cost = cost_control(&a, &b, temp2->nbr, temp2->bff);
						idx1 = find_pos(&a, temp2->bff);
						idx2 = find_pos(&b, temp2->nbr);
						printf("NBR: %d & BFF: %d == COST: %d\n", temp2->nbr, temp2->bff, cost_control(&a, &b, temp2->nbr, temp2->bff));
					}
					temp2 = temp2->next;
				}
				put_top_a(&a, idx1, counter);
				put_top_b(&b, idx2, counter);
				pa(&b, &a, counter);
			}
			put_top_a(&a, find_pos(&a, lst_min(&a)), counter);
		}	
	}
	else
		error();
	temp1 = a;
	temp2 = b;
	while (temp1 != NULL)
	{
		printf("STACK A NBR: %d\n", temp1->nbr);
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		printf("STACK B NBR: %d\n", temp2->nbr);
		printf("STACK B BFF: %d\n", temp2->bff);
		temp2 = temp2->next;
	}
	printf("Moves: %d\n", counter->moves);
}

