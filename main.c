/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:43 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/04 14:46:04 by rafilipe         ###   ########.fr       */
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
	
/* 	if (argc == 2)
	{
		printf("HERE\n");
		check_args(argc, ft_split(argv[1], ' '));
		
		a = get_stack(argc, ft_split(argv[1], ' '));
	} */
	if (argc > 2)
	{
		check_args(argc, argv);
		a = get_stack(argc, argv);
	}
	else
		error();
	temp1 = a;
	while (temp1 != NULL)
	{
		printf("%d\n", temp1->nbr);
		temp1 = temp1->next;
	}
	printf("a %p\n", a);
	printf("b %p\n", b);
	pb(&a, &b, counter);
	printf("a %p\n", a);
	printf("b %p\n", b);
	
	pb(&a, &b, counter);
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
