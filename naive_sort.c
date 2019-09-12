/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:24:37 by adavis            #+#    #+#             */
/*   Updated: 2019/09/10 20:00:41 by adavis           ###   ########.fr       */
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

void	naive_sort(int argc, t_ilist **a, t_ilist **b)
{
	int		i;

	i = 1;
	while ((*a)->next && !is_sorted(*a))
	{
		if (r_rr(*a, ilistlen(*a), i))
		{
			while ((*a)->i != i)
			{
				ft_printf("ra\n");
				rotate(a);
			}
		}
		else
		{
			while ((*a)->i != i)
			{
				ft_printf("rra\n");
				reverse_rotate(a);
			}
		}
		push(b, a);
		ft_printf("pb\n");
		i++;
	}
	while (*b)
	{
		push(a, b);
		ft_printf("pa\n");
	}
}
