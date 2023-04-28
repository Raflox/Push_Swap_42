/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:45 by rafilipe          #+#    #+#             */
/*   Updated: 2023/04/19 14:24:22 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"


void	swap(t_stack *s)
{
	int	aux;

	if (!(s->next))
		return ;
	aux = s->nbr;
	s->nbr = s->next->nbr;
	s->next->nbr = aux;
}

/* // Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a)
{
	;
}

// Swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements.
void	sb(t_stack **b)
{
	;
}

// sa and sb at the same time
void	ss(t_stack **a, t_stack **b)
{
	;
} */