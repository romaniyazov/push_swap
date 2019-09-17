/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:28:05 by adavis            #+#    #+#             */
/*   Updated: 2019/09/17 12:44:53 by adavis           ###   ########.fr       */
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

void	print_ops(t_stack *ops)
{
	while (ops)
	{
		if (ops->nbr == 1)
			ft_putendl("sa");
		if (ops->nbr == 4)
			ft_putendl("pa");
		if (ops->nbr == 5)
			ft_putendl("pb");
		if (ops->nbr == 6)
			ft_putendl("ra");
		if (ops->nbr == 7)
			ft_putendl("rb");
		if (ops->nbr == 8)
			ft_putendl("rr");
		if (ops->nbr == 9)
			ft_putendl("rra");
		if (ops->nbr == 10)
			ft_putendl("rrb");
		if (ops->nbr == 11)
			ft_putendl("rrr");
		ops = ops->next;
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
	if (!args_to_ilist(argc, argv, &a))
		terminate(&a, &a);
	index_ilist(a, argc - 1);
	if (argc == 4 && !is_sorted(a))
		sort_three(&a, ops);
	else if (argc == 6 && !is_sorted(a))
		sort_five(&a, &b, ops);
	else if (!is_sorted(a))
	{
		partition_sort(&a, &b, ops);
		optimize_ops(&ops);
	}
	print_ops(ops);
	ilistdel(&a);
	ilistdel(&b);
	stackdel(&oops);
}
