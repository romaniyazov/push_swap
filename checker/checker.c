/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:11:59 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:22:27 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	terminate(t_stack **a, t_stack **b)
{
	stackdel(a);
	stackdel(b);
	write(2, "Error\n", 6);
	exit(0);
}

int		is_instruction(char *inst)
{
	int		i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(inst, I[i]))
			return (1);
		i++;
	}
	return (0);
}

void	read_instructions2(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strcmp(line, "rra"))
		reverse_rotate(a);
	if (!ft_strcmp(line, "rrb"))
		reverse_rotate(b);
	if (!ft_strcmp(line, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	if (!ft_strcmp(line, "pa"))
		push(a, b);
	if (!ft_strcmp(line, "pb"))
		push(b, a);
	if (!ft_strcmp(line, "sb"))
		swap(b);
}

void	read_instructions(t_stack **a, t_stack **b)
{
	char	*line;
	int		cnt;

	cnt = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strlen(line))
			return ;
		if (!is_instruction(line))
			terminate(a, b);
		if (!ft_strcmp(line, "sa"))
			swap(a);
		if (!ft_strcmp(line, "ss"))
		{
			swap(a);
			swap(b);
		}
		if (!ft_strcmp(line, "ra"))
			rotate(a);
		if (!ft_strcmp(line, "rb"))
			rotate(b);
		read_instructions2(a, b, line);
		cnt++;
		ft_strdel(&line);
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		exit(0);
	if (!args_to_list(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	b = NULL;
	read_instructions(&a, &b);
	if (is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stackdel(&a);
	stackdel(&b);
}
