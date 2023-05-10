/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:48:11 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/10 16:42:53 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	 lst_add(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = lst_last(*lst);
		last -> next = new;
	}
}

t_stack	*lst_new(int content)
{
	t_stack			*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = content;
	new -> next = NULL;
	return (new);
}

t_stack	*lst_last(t_stack *lst)
{
	t_stack	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

int	lst_size(t_stack *lst)
{
	t_stack	*temp;
	int		len;

	temp = lst;
	len = 0;
	if (!lst)
		return (0);
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

// Function to calculate avg on stack
int	lst_avg(t_stack **a)
{
	t_stack			*temp;
	long long int	avg;
	int				i;

	i = 0;
	avg = 0;
	temp = *a;
	while (temp)
	{
		avg += (temp)->nbr;
		temp = (temp)->next;
		i++;
	}
	avg = avg / i;
	return (avg);
}
