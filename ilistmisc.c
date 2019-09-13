/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilistmisc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:27:58 by adavis            #+#    #+#             */
/*   Updated: 2019/09/13 16:31:49 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ilistlen(t_ilist *s)
{
	int		cnt;

	cnt = 0;
	while (s)
	{
		cnt++;
		s = s->next;
	}
	return (cnt);
}

int		ilistmax(t_ilist *s)
{
	int		max;

	max = s->i;
	while (s)
	{
		if (s->i > max)
			max = s->i;
		s = s->next;
	}
	return (max);
}

int		ilistmin(t_ilist *s)
{
	int		min;

	min = s->i;
	while (s)
	{
		if (s->i < min)
			min = s->i;
		s = s->next;
	}
	return (min);
}
