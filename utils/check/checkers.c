/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:55:00 by rafilipe          #+#    #+#             */
/*   Updated: 2023/04/19 15:01:36 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_int(char *arg) // atoi , itoa - strcmp (atoi == itoa)
{
	int	nbr;

	if (!ft_strcmp(arg, "0"))
		return (1);
	nbr = ft_atoi(arg);
	if (nbr > INT_MAX || nbr < INT_MIN || nbr == 0)
		return (0);
	return (1);
}

int	is_dup(int ac, char **av, int i)
{
	int	j;

	j = 0;
	while (j != i && j != ac)
	{
		if (av[j] == av[i])
			return (1);
		j++;
	}
	return (0);
}

void	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit(0);
	while (i != ac)
	{
		if (!is_int(av[i]) || is_dup(ac, av, i))
			error();
		i++;
	}
}
