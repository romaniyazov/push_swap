/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:44:19 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:48:22 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		r_rr(t_ilist *s, int argc, int i)
{
	int		cnt;
	t_ilist	*ss;

	ss = s;
	cnt = 0;
	while (s->i != i)
	{
		if (s->next)
			s = s->next;
		else
			s = ss;
		cnt++;
	}
	if (cnt > argc / 2)
		return (0);
	return (1);
}
