/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:19:25 by adavis            #+#    #+#             */
/*   Updated: 2019/09/08 19:44:43 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stack	*stacknew(int nbr)
{
	t_stack		*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->nbr = nbr;
	s->next = NULL;
	return (s);
}

void	stackpush(int nbr, t_stack **s)
{
	t_stack		*s_new;

	s_new = stacknew(nbr);
	s_new->next = *s;
	*s = s_new;
}

void	stackpushback(int nbr, t_stack *s)
{
	t_stack		*s_new;

	s_new = stacknew(nbr);
	while (s->next)
		s = s->next;
	s->next = s_new;
}
int		stackpoplast(t_stack *s)
{
	t_stack		*tmp;
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

int		stackpopfirst(t_stack **s)
{
	t_stack		*tmp;
	int			nbr;

	if (!(*s)->next)
	{
		nbr = (*s)->nbr;
		stackdel(s);
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

void	stackdel(t_stack **s)
{
	t_stack		*tmp;
	t_stack		*ss;

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
