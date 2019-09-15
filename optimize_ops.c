/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:47:31 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 19:26:21 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_ops(t_stack **ops)
{
	char	flag;
	t_stack	*oops;
	t_stack *tmp;
	t_stack	*ttmp;

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
			else if (oops->nbr == 6 && oops->next->nbr == 8)
			{
				tmp = oops;
				oops = oops->next;
				while (oops->nbr == 8)
				{
					ttmp = oops;
					oops = oops->next;
				}
				if (oops->nbr == 7)
				{
					ttmp->next = oops->next;
					tmp->nbr = 8;
					free(oops);
					oops = ttmp;
					flag = 1;
				}
			}
			else if (oops->nbr == 9 && oops->next->nbr == 10)
			{
				oops->nbr = 11;
				tmp = oops->next;
				oops->next = oops->next->next;
				free(tmp);
				flag = 1;
			}
			else if (oops->nbr == 9 && oops->next->nbr == 11)
			{
				tmp = oops;
				oops = oops->next;
				while (oops->nbr == 11)
				{
					ttmp = oops;
					oops = oops->next;
				}
				if (oops->nbr == 10)
				{
					ttmp->next = oops->next;
					tmp->nbr = 11;
					free(oops);
					oops = ttmp;
					flag = 1;
				}
			}
			oops = oops->next;
		}
	}
}
