/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:27:11 by adavis            #+#    #+#             */
/*   Updated: 2019/09/13 16:43:51 by adavis           ###   ########.fr       */
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
			//ft_printf("r%c\n", name);
			stackpushback(name == 'a' ? 6 : 7, ops);
		}
	}
	else
	{
		while ((*s)->i != n)
		{
			ireverse_rotate(s);
			//ft_printf("rr%c\n", name);
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

void	partition_sort(t_ilist **a, t_ilist **b, t_stack *ops)
{
	int		c_size;
	int		c_cnt;
	int		n;
	int		cnt;

	c_size = 21;
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
		//ft_printf("pb\n");
		stackpushback(5, ops);
		cnt++;
		if (cnt == c_size)
		{
			cnt = 0;
			c_cnt++;
		}
	}
	while (*b)
	{
		scroll_to_n(b, ilistmax(*b), 'b', ops);
		ipush(a, b);
		//ft_printf("pa\n");
		stackpushback(4, ops);
	}
}
