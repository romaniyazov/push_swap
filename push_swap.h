/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:31:27 by adavis            #+#    #+#             */
/*   Updated: 2019/09/12 16:27:42 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

t_ilist				*ilistnew(int nbr, int i);
void				ilistpush(int nbr, int i, t_ilist **s);
void				ilistpushback(int nbr, int i, t_ilist *s);
int					ilistpoplast(t_ilist *s, int *i);
int					ilistpopfirst(t_ilist **s);
void				ilistdel(t_ilist **s);

void				push(t_ilist **a, t_ilist **b);
void				swap(t_ilist **s);
void				rotate(t_ilist **s);
void				reverse_rotate(t_ilist **s);

int					is_sorted(t_ilist *s);

void				sort_three(t_ilist *a);
void				sort_more(int argc, t_ilist *a, t_ilist *b);
void				naive_sort(int argc, t_ilist **a, t_ilist **b);

void				partition_sort(int argc, t_ilist **a, t_ilist **b);

int					r_rr(t_ilist *s, int argc, int i);

int					ilistlen(t_ilist *s);

int					ilistmin(t_ilist *s);
int					ilistmax(t_ilist *s);

#endif
