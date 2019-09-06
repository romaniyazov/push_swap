/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:19:25 by adavis            #+#    #+#             */
/*   Updated: 2019/09/06 18:52:20 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*stacknew(int nbr)
{
	t_stack		*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->nbr = nbr;
	s->next = NULL;
	return (s);
}

t_stack	*stackpush(int nbr, t_stack *s)
{
	t_stack		*s_new;

	s_new = stacknew(nbr);
	s_new->next = s;
	return (s_new);
}

void	stackpushback(int nbr, t_stack *s)
{
	t_stack		*s_new;

	s_new = stacknew(nbr);
	while (s->next)
		s = s->next;
	s->next = s_new;
}
