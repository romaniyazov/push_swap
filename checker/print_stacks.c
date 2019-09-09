/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:35:48 by adavis            #+#    #+#             */
/*   Updated: 2019/09/08 22:01:33 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%5d", a->nbr);
			a = a->next;
		}
		else
			ft_printf("     ");
		if (b)
		{
			ft_printf("%5d", b->nbr);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("%5c%5c\n", '_', '_');
	ft_printf("\n%5c%5c\n", 'a', 'b');
}
