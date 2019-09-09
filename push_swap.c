/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:28:05 by adavis            #+#    #+#             */
/*   Updated: 2019/09/09 20:50:32 by adavis           ###   ########.fr       */
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

	b = NULL;
	if(!args_to_ilist(argc, argv, &a))
		terminate(&a, &a);
	index_ilist(a, argc - 1);
	//print_ilist(a);
	if (argc == 3 && !is_sorted(a))
		ft_printf("sa\n");
	if (argc == 4 && !is_sorted(a))
		sort_three(a);
	if (argc > 4 && !is_sorted(a))
		sort_more(argc, a, b);
	ilistdel(&a);
}
