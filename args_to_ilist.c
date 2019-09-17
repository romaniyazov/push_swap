/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_ilist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:47:18 by adavis            #+#    #+#             */
/*   Updated: 2019/09/17 13:14:43 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_in_list(t_ilist *s, int n)
{
	while (s)
	{
		if (s->nbr == n)
			return (1);
		s = s->next;
	}
	return (0);
}

int		isnbr(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		args_to_ilist(int argc, char **argv, t_ilist **s)
{
	int		i;

	if ((!ft_atoi(argv[1]) && ft_strcmp(argv[1], "0")) ||
			is_in_list(*s, ft_atoi(argv[1])) ||
			(argv[1][0] != '-' && ft_atoi(argv[1]) < 0) ||
			(argv[1][0] == '-' && ft_atoi(argv[1]) > 0) ||
			!isnbr(argv[1]))
		return (0);
	*s = ilistnew(ft_atoi(argv[1]), 0);
	i = 1;
	while (++i < argc)
	{
		if ((!ft_atoi(argv[i]) && ft_strcmp(argv[i], "0")) ||
			is_in_list(*s, ft_atoi(argv[i])) ||
			(argv[i][0] != '-' && ft_atoi(argv[i]) < 0) ||
			(argv[i][0] == '-' && ft_atoi(argv[i]) > 0) ||
			!isnbr(argv[i]))
		{
			ilistdel(s);
			return (0);
		}
		ilistpushback(ft_atoi(argv[i]), 0, *s);
	}
	return (1);
}
