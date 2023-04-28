/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:39 by rafilipe          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:56 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

/*** UTILS ***/

/* Check */

/* Error */
void	error(void);
/* Get */

/* Lib */
int		mod_atoi(const char *str);
void	lst_add(t_stack *lst, t_stack *new);
t_stack	*lst_new(int content);
t_stack	*lst_last(t_stack *lst);

/* Move */
void	swap(t_stack *s);

#endif