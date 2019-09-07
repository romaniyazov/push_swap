/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:08:14 by adavis            #+#    #+#             */
/*   Updated: 2019/09/07 17:17:41 by adavis           ###   ########.fr       */
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

void	read_instuctions(t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(1, &line) > 0)
	{
		if (!ft_strcmp(line, "sa"))
			swap(&a);
		if (!ft_strcmp(line, "sb"))
			swap(&b);
		if (!ft_strcmp(line, "ss"))
		{
			swap(&a);
			swap(&b);
		}
		if (!ft_strcmp(line, "ra"))
			rotate(&a);
		if (!ft_strcmp(line, "rb"))
			rotate(&b);
		if (!ft_strcmp(line, "rr"))
		{
			rotate(&a);
			rotate(&b);
		}
		if (!ft_strcmp(line, "rra"))
			reverse_rotate(&a);
		if (!ft_strcmp(line, "rrb"))
			reverse_rotate(&b);
		if (!ft_strcmp(line, "rrr"))
		{
			reverse_rotate(&a);
			reverse_rotate(&b);
		}
		if (!ft_strcmp(line, "pa"))
			push(&a, &b);
		if (!ft_strcmp(line, "pb"))
			push(&b, &a);
		ft_strdel(&line);
		print_stacks(a, b);		// debug print
	}
}

int		main(int argc, char** argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;
	int			n;
	char		*line;
	
	if (argc < 2)
		exit(0);
	a = stacknew(ft_atoi(argv[1]));
	b = NULL;
	i = 1;
	while (++i < argc)
		stackpushback(ft_atoi(argv[i]), a);
	print_stacks(a, b);
	read_instuctions(a, b);
	//if (!b && is_sorted(a))
	//	ft_printf("OK\n");
	//else
	//	ft_printf("KO\n");
	stackdel(&a);
	stackdel(&b);
}
