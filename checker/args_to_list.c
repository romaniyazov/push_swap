/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:47:18 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 18:51:49 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_in_list(t_stack *s, int n)
{
	while (s)
	{
		if (s->nbr == n)
			return (1);
		s = s->next;
	}
	return (0);
}

int		args_to_list(int argc, char **argv, t_stack **s)
{
	int		i;

	if ((!ft_atoi(argv[1]) && (ft_strlen(argv[1]) != 1 || argv[1][0] != '0')) ||
			is_in_list(*s, ft_atoi(argv[1])) ||
			(argv[1][0] != '-' && ft_atoi(argv[1]) < 0) ||
			(argv[1][0] == '-' && ft_atoi(argv[1]) > 0))
		return (0);
	*s = stacknew(ft_atoi(argv[1]));
	i = 1;
	while (++i < argc)
	{
		if ((!ft_atoi(argv[i]) &&
							(ft_strlen(argv[i]) != 1 || argv[i][0] != '0')) ||
			is_in_list(*s, ft_atoi(argv[i])) ||
			(argv[i][0] != '-' && ft_atoi(argv[i]) < 0) ||
			(argv[i][0] == '-' && ft_atoi(argv[i]) > 0))
		{
			stackdel(s);
			return (0);
		}
		stackpushback(ft_atoi(argv[i]), *s);
	}
	return (1);
}
