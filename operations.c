/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:56:25 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:46:33 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ipush(t_ilist **a, t_ilist **b)
{
	int		nbr;
	int		i;

	if (*b)
	{
		i = (*b)->i;
		nbr = ilistpopfirst(b);
	}
	else
		return ;
	if (*a)
		ilistpush(nbr, i, a);
	else
		*a = ilistnew(nbr, i);
}

void	iswap(t_ilist **s)
{
	int		a;
	int		ai;
	int		b;
	int		bi;

	if (!(*s) || !(*s)->next)
		return ;
	ai = (*s)->i;
	a = ilistpopfirst(s);
	bi = (*s)->i;
	b = ilistpopfirst(s);
	ilistpush(a, ai, s);
	ilistpush(b, bi, s);
}

void	irotate(t_ilist **s)
{
	int		nbr;
	int		i;

	if (!(*s) || !(*s)->next)
		return ;
	i = (*s)->i;
	nbr = ilistpopfirst(s);
	ilistpushback(nbr, i, *s);
}

void	ireverse_rotate(t_ilist **s)
{
	int		a;
	int		i;

	if (!(*s) || !(*s)->next)
		return ;
	a = ilistpoplast(*s, &i);
	ilistpush(a, i, s);
}
