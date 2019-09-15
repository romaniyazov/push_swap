/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:08:05 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:45:20 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_six(t_ilist **a, t_ilist **b, t_stack *ops)
{
	scroll_to_n(a, 5, 'a', ops);
	ipush(b, a);
	stackpushback(5, ops);
	scroll_to_n(a, 4, 'a', ops);
	ipush(b, a);
	stackpushback(5, ops);
	sort_three(a, ops);
	if (!is_sorted(*b))
	{
		iswap(b);
		stackpushback(2, ops);
	}
	scroll_to_n(a, 1, 'a', ops);
	ipush(a, b);
	stackpushback(4, ops);
	scroll_to_n(a, 1, 'a', ops);
	ipush(a, b);
	stackpushback(4, ops);
	scroll_to_n(a, 1, 'a', ops);
}
