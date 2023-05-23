/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:43 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 16:49:03 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	if (argc > 1)
	{
		a = get_stack(argc, argv);
		if (!a || checkdup(&a))
		{
			free_stack(&a);
			error();
		}
		sort_moves(a, b);
	}
	else
		return (0);
	free_stack(&a);
	return (0);
}
