/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:43 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/08 13:00:54 by rafilipe         ###   ########.fr       */
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


	// if ac == 2 -> split and check
	// if ac > 2 -> check
	// if ac == 1 -> exit

	a = NULL;
	b = NULL;
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
			while (lst_size(a) > 5 && a)
			{
				printf("SIZE: %d\n", lst_size(a));
				if (((*a).nbr) < lst_avg(&a))
					pb(&a, &b, counter);
				else
					ra(&a, counter);
			}
			printf("AVG: %d\n", lst_avg(&a));
		}
	}
	else
		error();
	temp1 = a;
	temp2 = b;
	while (temp1 != NULL)
	{
		printf("STACK A: %d\n", temp1->nbr);
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		printf("STACK B: %d\n", temp2->nbr);
		temp2 = temp2->next;
	}
	printf("Moves: %d\n", counter->moves);
}

