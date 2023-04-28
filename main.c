/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:43 by rafilipe          #+#    #+#             */
/*   Updated: 2023/04/19 15:03:58 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	/* t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	
	check_args(argc, argv); */
	
	t_stack	head;
/* 	t_stack	node; */
	t_stack *ptr;

	ptr = &head;
	
	head.nbr = 42;
	head.next = NULL;
/* 	node.nbr = 21;
	node.next = NULL; */
	

	/* printf("%d\n", head.nbr); */
	while (ptr != NULL)
	{
		printf("%d\n", ptr->nbr);
		ptr = ptr->next;
	}
	
 	swap(&head);

	ptr = &head;
	while (ptr != NULL)
	{
		printf("swap: %d\n", ptr->nbr);
		ptr = ptr->next;
	} 

	printf("ATOI: %d\n", mod_atoi("23456ar567"));

}
