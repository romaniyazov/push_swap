/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:24:37 by adavis            #+#    #+#             */
/*   Updated: 2019/09/13 16:28:08 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	naive_sort(t_ilist **a, t_ilist **b)
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
