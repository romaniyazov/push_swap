/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:31:27 by adavis            #+#    #+#             */
/*   Updated: 2019/09/18 13:08:38 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stacks.h"

typedef struct		s_ilist
{
	int				i;
	int				nbr;
	struct s_ilist	*next;
}					t_ilist;

int					args_to_ilist(int argc, char **argv, t_ilist **s);

int					find_min(t_ilist *s);
void				index_min(t_ilist *s, int min, int i);
void				index_ilist(t_ilist *s, int total);

/*
**	Indexed list methods
*/
t_ilist				*ilistnew(int nbr, int i);
void				ilistpush(int nbr, int i, t_ilist **s);
void				ilistpushback(int nbr, int i, t_ilist *s);
int					ilistpoplast(t_ilist *s, int *i);
int					ilistpopfirst(t_ilist **s);
void				ilistdel(t_ilist **s);
int					ilistlen(t_ilist *s);
int					ilistmin(t_ilist *s);
int					ilistmax(t_ilist *s);

/*
**	Indexed list operations
*/
void				ipush(t_ilist **a, t_ilist **b);
void				iswap(t_ilist **s);
void				irotate(t_ilist **s);
void				ireverse_rotate(t_ilist **s);

/*
**	Sorting methods
*/
void				sort_three(t_ilist **a, t_stack *ops);
void				sort_five(t_ilist **a, t_ilist **b, t_stack *ops);
void				partition_sort(t_ilist **a, t_ilist **b, t_stack *ops);

/*
**	Sorting helpers
*/
int					r_rr(t_ilist *s, int argc, int i);
void				optimize_ops(t_stack **ops);
void				scroll_to_n(t_ilist **s, int n, char name, t_stack *ops);
int					find_nearest(t_ilist *s, int n);
int					is_sorted(t_ilist *s);

#endif
