/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_ilist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:47:18 by adavis            #+#    #+#             */
/*   Updated: 2019/09/22 14:26:57 by adavis           ###   ########.fr       */
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

int		isint(char *str)
{
	int		neg;
	char	*s;

	neg = 0;
	if (*str == '-' || *str == '+')
	{
		str++;
		neg = 1;
	}
	else if (*str == '+')
		str++;
	else if (!ft_isdigit(*str))
		return (0);
	s = str;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	if ((!neg && ft_strlen(str) == 10 && ft_strcmp(str, "2147483647") > 0) ||
		(neg && ft_strlen(str) == 10 && ft_strcmp(str, "2147483648") > 0) ||
		(ft_strlen(str) > 10))
		return (0);
	return (1);
}

int		args_to_ilist(int argc, char **argv, t_ilist **s)
{
	int		i;

	if ((!ft_atoi(argv[0]) && ft_strcmp(argv[0], "0")) || !isint(argv[0]))
		return (0);
	*s = ilistnew(ft_atoi(argv[0]), 0);
	i = 0;
	while (++i < argc - 1)
	{
		if ((!ft_atoi(argv[i]) && ft_strcmp(argv[i], "0")) ||
			is_in_list(*s, ft_atoi(argv[i])) ||
			!isint(argv[i]))
		{
			ilistdel(s);
			return (0);
		}
		ilistpushback(ft_atoi(argv[i]), 0, *s);
	}
	return (1);
}
