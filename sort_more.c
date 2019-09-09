/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:19:10 by adavis            #+#    #+#             */
/*   Updated: 2019/09/09 21:01:34 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(int argc, t_ilist *a, t_ilist *b)
{
	while (!is_sorted(a) || b)
	{
		if (a->i > a->next->i && a->next->i != 1)
		{
			push(&b, &a);
			ft_printf("pb\n");
			while ((a->i != b->i - 1) && (a->i != 1 && b->i != argc))
			{
				rotate(&a);
				ft_printf("ra\n");
			}
			rotate(&a);
			ft_printf("ra\n");
			rotate(&a);
			ft_printf("ra\n");
			push(&a, &b);
			ft_printf("pa\n");
		}
		rotate(&a);
		ft_printf("ra\n");
	}
}
