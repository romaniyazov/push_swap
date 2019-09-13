/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:28:05 by adavis            #+#    #+#             */
/*   Updated: 2019/09/13 17:31:20 by adavis           ###   ########.fr       */
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

	b = NULL;
	ops = stacknew(0);
	if(!args_to_ilist(argc, argv, &a))
		terminate(&a, &a);
	index_ilist(a, argc - 1);
	//print_ilist(a);
	// if (argc == 3 && !is_sorted(a))
	// 	ft_printf("sa\n");
	// else if (argc == 4 && !is_sorted(a))
	// 	sort_three(a);
	// else
	// {
		partition_sort(&a, &b, ops);
	//	naive_sort(&a, &b);
	// }
	//optimize_ops(&ops);
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
		ops = ops->next;
	}
	ilistdel(&a);
	ilistdel(&b);
}
