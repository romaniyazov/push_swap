/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:47:31 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:56:39 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	oops1(t_stack **oops, int n)
{
	t_stack	*tmp;

	(*oops)->nbr = n;
	tmp = (*oops)->next;
	(*oops)->next = (*oops)->next->next;
	free(tmp);
	return (1);
}

char	oops2(t_stack **oops, int n)
{
	t_stack	*tmp;
	t_stack	*ttmp;

	tmp = *oops;
	*oops = (*oops)->next;
	while ((*oops)->nbr == n)
	{
		ttmp = *oops;
		*oops = (*oops)->next;
	}
	if ((*oops)->nbr == n - 1)
	{
		ttmp->next = (*oops)->next;
		tmp->nbr = n;
		free(*oops);
		*oops = ttmp;
		return (1);
	}
	return (0);
}

void	optimize_ops(t_stack **ops)
{
	char	flag;
	t_stack	*oops;

	flag = 1;
	while (flag)
	{
		flag = 0;
		oops = *ops;
		while (oops)
		{
			if (oops->nbr == 6 && oops->next->nbr == 7)
				flag = oops1(&oops, 8);
			else if (oops->nbr == 6 && oops->next->nbr == 8)
				flag = oops2(&oops, 8);
			else if (oops->nbr == 9 && oops->next->nbr == 10)
				flag = oops1(&oops, 11);
			else if (oops->nbr == 9 && oops->next->nbr == 11)
				flag = oops2(&oops, 11);
			oops = oops->next;
		}
	}
}
