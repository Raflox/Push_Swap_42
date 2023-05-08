/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:55:00 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/05 12:48:48 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->nbr > temp->next->nbr)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/* int	is_int(char *arg) // atoi , itoa - strcmp (atoi == itoa)
{
	int	nbr;

	if (!ft_strncmp(arg, "0", ft_strlen(arg)))
		return (1);
	nbr = mod_atoi(arg);
	if (nbr > INT_MAX || nbr < INT_MIN || nbr == 0)
		return (0);
	return (1);
} */

int	checkdup(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *a;
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (temp->nbr == temp2->nbr)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

/* void	check_args(int ac, char **args)
{
	int	i;

	i = 1;
	while (i != ac)
	{
		if (!is_int(args[i]))
			error();
		i++;
	}
} */