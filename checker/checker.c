/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:08:14 by adavis            #+#    #+#             */
/*   Updated: 2019/09/06 20:18:38 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack *s)
{
	while (s)
	{
		ft_printf("%d\n", s->nbr);
		s = s->next;
	}
}

int		main(int argc, char** argv)
{
	t_stack		*a;
	int			i;
	int			n;
	char		*line;
	
	if (argc < 2)
		exit(0);
	else
	{
		a = stacknew(ft_atoi(argv[1]));
		i = 1;
		while (++i < argc)
			stackpushback(ft_atoi(argv[i]), a);
		print_stack(a);
		while (get_next_line(1, &line) > 0)
		{
			ft_printf("%s\n", line);
			ft_strdel(&line);
		}
		stackdel(a);
	}
}
