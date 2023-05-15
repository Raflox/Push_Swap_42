/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:39 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/15 18:01:00 by rafilipe         ###   ########.fr       */
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
	int				bff;
	int				cost;
	int				index;
	struct s_stack	*next;
}	t_stack;

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
int		lst_min(t_stack **stack); // DELETE
int		lst_max(t_stack *lst); // DELETE
int		lst_nbr_index(t_stack **a, int nbr); // DELETE
int		find_bff(t_stack **a, int nb);
int		find_pos(t_stack **stack, int nbr);
int		cost_control(t_stack **a, t_stack **b, int nbr, int bff);
void	put_top_a(t_stack **lst, int index);
void	put_top_b(t_stack **lst, int index);

/* Moves */
void	swap(t_stack **s);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **s);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **s);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* Sort */
void	sort(t_stack **a);
void	sort_3(t_stack **a);

#endif