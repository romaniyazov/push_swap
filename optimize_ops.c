/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:47:31 by adavis            #+#    #+#             */
/*   Updated: 2019/09/13 17:28:15 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_ops(t_stack **ops)
{
	char	flag;
	t_stack	*oops;
	t_stack *tmp;

	flag = 1;
	while (flag)
	{
		flag = 0;
		oops = *ops;
		while (oops)
		{
			if (oops->nbr == 6 && oops->next->nbr == 7)
			{
				oops->nbr = 8;
				tmp = oops->next;
				oops->next = oops->next->next;
				free(tmp);
				flag = 1;
			}
			oops = oops->next;
		}
	}
}