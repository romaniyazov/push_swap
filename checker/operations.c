/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:56:25 by adavis            #+#    #+#             */
/*   Updated: 2019/09/07 17:15:50 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **a, t_stack **b)
{
	int		nbr;

	if (*b)
		nbr = stackpopfirst(b);
	else
		return ;
	if (*a)
		stackpush(nbr, a);
	else
		*a = stacknew(nbr);
	ft_putchar('\n');
}

void	swap(t_stack **s)
{
	int		a;
	int		b;

	if (!(*s) || !(*s)->next)
		return ;
	a = stackpopfirst(s);
	b = stackpopfirst(s);
	stackpush(a, s);
	stackpush(b, s);
}

void	rotate(t_stack **s)
{
	int		a;

	if (!(*s) || !(*s)->next)
		return ;
	a = stackpopfirst(s);
	stackpushback(a, *s);
}

void	reverse_rotate(t_stack **s)
{
	int		a;

	if (!(*s) || !(*s)->next)
		return ;
	a = stackpoplast(*s);
	stackpush(a, s);
}
