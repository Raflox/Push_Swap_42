/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:45 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 16:24:32 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack **s)
{
	int	aux;

	aux = (*s)->nbr;
	(*s)->nbr = (*s)->next->nbr;
	(*s)->next->nbr = aux;
}

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

// Swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements.
void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

// sa and sb at the same time
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
