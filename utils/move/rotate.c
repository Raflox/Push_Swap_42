/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:47 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 16:23:02 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	aux = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = aux;
	aux->next = NULL;
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

// ra and rb at the same time.
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
