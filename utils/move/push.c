/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:52 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 16:23:30 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*aux;

	if (!*src)
		return ;
	aux = *src;
	*src = (*src)->next;
	aux->next = *dst;
	*dst = aux;
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
