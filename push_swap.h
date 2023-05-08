/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:39 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/08 12:29:11 by rafilipe         ###   ########.fr       */
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

typedef struct s_count
{
	int		moves;
}	t_count;

/*** UTILS ***/

/* Check */
void	check_args(int argc, char **argv);
void	check_args2(int argc, char **argv);
int		is_sorted(t_stack **a);
int		checkdup(t_stack **a);

/* Error */
void	error(void);

/* Get */
t_stack	*get_stack(int argc, char **argv);
t_stack	*get_str_stack(char **argv);

/* Lib */
int		mod_atoi(const char *str);
int		lst_avg(t_stack **a);
void	lst_add(t_stack **lst, t_stack *new);
t_stack	*lst_new(int content);
t_stack	*lst_last(t_stack *lst);
void	free_stack(t_stack **stack);
int		lst_size(t_stack *lst);
int		lst_min(t_stack *lst);
int		lst_max(t_stack *lst);

/* Moves */
void	swap(t_stack **s);
void	sa(t_stack **a, t_count *counter);
void	sb(t_stack **b, t_count *counter);
void	ss(t_stack **a, t_stack **b, t_count *counter);
void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **a, t_stack **b, t_count *counter);
void	pb(t_stack **a, t_stack **b, t_count *counter);
void	rotate(t_stack **s);
void	ra(t_stack **a, t_count *counter);
void	rb(t_stack **b, t_count *counter);
void	rr(t_stack **a, t_stack **b, t_count *counter);
void	rev_rotate(t_stack **s);
void	rra(t_stack **a, t_count *counter);
void	rrb(t_stack **b, t_count *counter);
void	rrr(t_stack **a, t_stack **b, t_count *counter);

/* Sort */
void	sort_3(t_stack **a, t_count *counter);

#endif