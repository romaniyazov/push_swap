/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_ilist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:15:02 by adavis            #+#    #+#             */
/*   Updated: 2019/09/09 18:15:17 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_ilist *s)
{
	int		min;

	while (s->i)
		s = s->next;
	min = s->nbr;
	while (s)
	{
		if (s->nbr < min && !s->i)
			min = s->nbr;
		s = s->next;
	}
	return (min);
}

void	index_min(t_ilist *s, int min, int i)
{
	while(s->nbr != min)
		s = s->next;
	s->i = i;
}

void	index_ilist(t_ilist *s, int total)
{
	int			min;
	int			i;

	i = 1;
	while (i <= total)
	{
		min = find_min(s);
		index_min(s, min, i);
		i++;
	}
}
