/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:28:05 by adavis            #+#    #+#             */
/*   Updated: 2019/09/14 13:51:08 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(t_ilist **a, t_ilist **b)
{
	ilistdel(a);
	ilistdel(b);
	write(2, "Error\n", 6);
	exit(0);
}

void	print_ilist(t_ilist *s)
{
	while (s)
	{
		ft_printf("%d: %d\n", s->i, s->nbr);
		s = s->next;
	}
}

int		main(int argc, char **argv)
{
	t_ilist		*a;
	t_ilist		*b;
	t_stack		*ops;
	t_stack		*oops;

	b = NULL;
	ops = stacknew(0);
	oops = ops;
	if(!args_to_ilist(argc, argv, &a))
		terminate(&a, &a);
	index_ilist(a, argc - 1);
	partition_sort(&a, &b, ops);
	optimize_ops(&ops);
	while (ops)
	{
		if (ops->nbr == 4)
			ft_printf("pa\n");
		if (ops->nbr == 5)
			ft_printf("pb\n");
		if (ops->nbr == 6)
			ft_printf("ra\n");
		if (ops->nbr == 7)
			ft_printf("rb\n");
		if (ops->nbr == 8)
			ft_printf("rr\n");
		if (ops->nbr == 9)
			ft_printf("rra\n");
		if (ops->nbr == 10)
			ft_printf("rrb\n");
		if (ops->nbr == 11)
			ft_printf("rrr\n");
		ops = ops->next;
	}
	ilistdel(&a);
	ilistdel(&b);
	stackdel(&oops);
}
