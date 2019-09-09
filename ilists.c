/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilists.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:36:21 by adavis            #+#    #+#             */
/*   Updated: 2019/09/09 14:31:51 by adavis           ###   ########.fr       */
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
int		ilistpoplast(t_ilist *s)
{
	t_ilist		*tmp;
	int			nbr;

	while (s->next)
	{
		tmp = s;
		s = s->next;
	}
	nbr = s->nbr;
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

void	ilistdel(t_ilist **s)
{
	t_ilist		*tmp;
	t_ilist		*ss;

	if (!*s)
		return ;
	ss = *s;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	ss = NULL;
}
