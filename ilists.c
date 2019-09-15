/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilists.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:36:21 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:47:41 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ilist	*ilistnew(int nbr, int i)
{
	t_ilist		*s;

	s = (t_ilist *)malloc(sizeof(t_ilist));
	s->i = i;
	s->nbr = nbr;
	s->next = NULL;
	return (s);
}

void	ilistpush(int nbr, int i, t_ilist **s)
{
	t_ilist		*s_new;

	s_new = ilistnew(nbr, i);
	s_new->next = *s;
	*s = s_new;
}

void	ilistpushback(int nbr, int i, t_ilist *s)
{
	t_ilist		*s_new;

	s_new = ilistnew(nbr, i);
	while (s->next)
		s = s->next;
	s->next = s_new;
}

int		ilistpoplast(t_ilist *s, int *i)
{
	t_ilist		*tmp;
	int			nbr;

	while (s->next)
	{
		tmp = s;
		s = s->next;
	}
	nbr = s->nbr;
	*i = s->i;
	free(s);
	tmp->next = NULL;
	return (nbr);
}

int		ilistpopfirst(t_ilist **s)
{
	t_ilist		*tmp;
	int			nbr;

	if (!(*s)->next)
	{
		nbr = (*s)->nbr;
		ilistdel(s);
	}
	else
	{
		tmp = *s;
		nbr = (*s)->nbr;
		*s = (*s)->next;
		free(tmp);
	}
	return (nbr);
}
