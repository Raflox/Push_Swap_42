/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:54:33 by rafilipe          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:35 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*get_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		nbr;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		lst_add(stack, lst_new(nbr));
		i++;
	}
	return (stack);
}
