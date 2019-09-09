/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:08:41 by adavis            #+#    #+#             */
/*   Updated: 2019/09/09 19:22:16 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ilist *a)
{
	if (a->i == 1 && a->next->i == 3)
	{
		ft_printf("sa\nra\n");
		return ;
	}
	if (a->i == 2 && a->next->i == 1)
	{
		ft_printf("sa\n");
		return ;
	}
	if (a->i == 2 && a->next->i == 3)
	{
		ft_printf("rra\n");
		return ;
	}
	if (a->i == 3 && a->next->i == 2)
	{
		ft_printf("sa\nrra\n");
		return ;
	}
	if (a->i == 3 && a->next->i == 1)
	{
		ft_printf("ra\n");
		return ;
	}
}
