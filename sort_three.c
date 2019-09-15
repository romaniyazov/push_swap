/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:08:41 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:39:04 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ilist **a, t_stack *ops)
{
	if ((*a)->i == 1 && (*a)->next->i == 3)
	{
		iswap(a);
		irotate(a);
		stackpushback(1, ops);
		stackpushback(6, ops);
	}
	if ((*a)->i == 2 && (*a)->next->i == 1)
	{
		iswap(a);
		stackpushback(1, ops);
	}
	if ((*a)->i == 2 && (*a)->next->i == 3)
	{
		ireverse_rotate(a);
		stackpushback(9, ops);
	}
	if ((*a)->i == 3 && (*a)->next->i == 2)
	{
		iswap(a);
		ireverse_rotate(a);
		stackpushback(1, ops);
		stackpushback(9, ops);
	}
	if ((*a)->i == 3 && (*a)->next->i == 1)
	{
		irotate(a);
		stackpushback(6, ops);
	}
}
