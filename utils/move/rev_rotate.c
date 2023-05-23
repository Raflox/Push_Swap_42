/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:50 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 16:23:56 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	aux = last->next;
	last->next = NULL;
	aux->next = *stack;
	*stack = aux;
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
