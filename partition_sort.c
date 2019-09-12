/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:27:11 by adavis            #+#    #+#             */
/*   Updated: 2019/09/12 22:57:47 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		closest(t_ilist *s, int min, int max)
{
	int		pos;
	int		i;
	int		i_pos;

	if (!s->next)
		return s->i;
	pos = 1;
	i_pos = ilistlen(s);
	while (s)
	{
		if (s->i >= min && s->i <= max)
		{
			if (pos < i_pos || ilistlen(s) - pos < i_pos)
				i = s->i;
		}
		pos++;
		s = s->next;
	}
	return (i);
}

void	scroll_to_n(t_ilist **s, int n, char name)
{
	if (r_rr(*s, ilistlen(*s), n))
	{
		while ((*s)->i != n)
		{
			rotate(s);
			ft_printf("r%c\n", name);
		}
	}
	else
	{
		while ((*s)->i != n)
		{
			reverse_rotate(s);
			ft_printf("rr%c\n", name);
		}
	}
}

int		find_nearest(t_ilist *s, int n)
{
	int		nearest;

	if (!s->next)
		return (s->i);
	nearest = s->i;
	while (s)
	{
		if (s->i < n && (s->i > nearest || nearest >= n))
			nearest = s->i;
		s = s->next;
	}
	return (nearest);
}

void	partition_sort(int argc, t_ilist **a, t_ilist **b)
{
	int		c_size;
	int		c_cnt;
	int		n;
	int		cnt;

	c_size = ilistlen(*a) / ft_sqrt(ilistlen(*a)) * 2;
	c_cnt = 0;
	cnt = 0;
	n = 1;
	while (*a)
	{
		n = closest(*a, c_cnt * c_size + 1, c_cnt * c_size + c_size);
		scroll_to_n(a, n, 'a');
		if (*b)
			scroll_to_n(b, find_nearest(*b, n), 'b');
		push(b, a);
		ft_printf("pb\n");
		cnt++;
		if (cnt == c_size)
		{
			cnt = 0;
			c_cnt++;
		}
	}
	while (*b)
	{
		scroll_to_n(b, ilistmax(*b), 'b');
		push(a, b);
		ft_printf("pa\n");
	}
}