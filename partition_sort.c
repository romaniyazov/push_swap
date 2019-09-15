/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:27:11 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:09:30 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		closest(t_ilist *s, int min, int max)
{
	int		pos;
	int		i;
	int		i_pos;
	int		s_len;

	if (!s->next)
		return (s->i);
	s_len = ilistlen(s);
	pos = 0;
	i_pos = s_len;
	while (s)
	{
		if (s->i >= min && s->i <= max)
		{
			if (pos < i_pos || s_len - pos < i_pos)
			{
				i = s->i;
				i_pos = pos;
			}
		}
		pos++;
		s = s->next;
	}
	return (i);
}

void	scroll_to_n(t_ilist **s, int n, char name, t_stack *ops)
{
	if (r_rr(*s, ilistlen(*s), n))
	{
		while ((*s)->i != n)
		{
			irotate(s);
			stackpushback(name == 'a' ? 6 : 7, ops);
		}
	}
	else
	{
		while ((*s)->i != n)
		{
			ireverse_rotate(s);
			stackpushback(name == 'a' ? 9 : 10, ops);
		}
	}
}

int		find_nearest(t_ilist *s, int n)
{
	int		nearest;
	t_ilist	*ss;

	ss = s;
	if (!s->next)
		return (s->i);
	nearest = 0;
	while (s)
	{
		if (s->i < n && s->i > nearest)
			nearest = s->i;
		s = s->next;
	}
	if (!nearest)
		nearest = ss->i;
	return (nearest);
}

void	a_to_b_sorted(t_ilist **a, t_ilist **b, t_stack *ops, int c_size)
{
	int		cnt;
	int		n;
	int		c_cnt;

	c_cnt = 0;
	cnt = 0;
	n = 1;
	while (*a)
	{
		n = closest(*a, c_cnt * c_size + 1, c_cnt * c_size + c_size);
		scroll_to_n(a, n, 'a', ops);
		if (*b)
			scroll_to_n(b, find_nearest(*b, n), 'b', ops);
		ipush(b, a);
		stackpushback(5, ops);
		cnt++;
		if (cnt == c_size)
		{
			cnt = 0;
			c_cnt++;
		}
	}
}

void	partition_sort(t_ilist **a, t_ilist **b, t_stack *ops)
{
	int		c_size;
	int		c_cnt;
	int		n;
	int		cnt;

	c_size = ilistlen(*a) / ft_sqrt(ilistlen(*a)) * 3 / 2;
	c_cnt = 0;
	cnt = 0;
	n = 1;
	a_to_b_sorted(a, b, ops, c_size);
	while (*b)
	{
		scroll_to_n(b, ilistmax(*b), 'b', ops);
		ipush(a, b);
		stackpushback(4, ops);
	}
}
