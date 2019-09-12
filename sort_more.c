/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:19:10 by adavis            #+#    #+#             */
/*   Updated: 2019/09/12 21:21:29 by adavis           ###   ########.fr       */
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

void	sort_more(int argc, t_ilist *a, t_ilist *b)
{
	while (!is_sorted(a) || b)
	{
		if (a->i > a->next->i && !(a->i == argc - 1 && a->next->i == 1))
		{
			push(&b, &a);
			ft_printf("pb\n");
			if (r_rr(a, argc, b->i + 1))
			{
				while (!(a->i == b->i + 1 || (a->i == 1 && b->i == argc - 1)))
				{
					rotate(&a);
					ft_printf("ra\n");
				}
			}
			else
			{
				while (!(a->i == b->i + 1 || (a->i == 1 && b->i == argc - 1)))
				{
					reverse_rotate(&a);
					ft_printf("rra\n");
				}
			}
			push(&a, &b);
			ft_printf("pa\n");
		}
		rotate(&a);
		ft_printf("ra\n");
	}
}
