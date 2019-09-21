/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:47:18 by adavis            #+#    #+#             */
/*   Updated: 2019/09/21 17:24:49 by adavis           ###   ########.fr       */
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
	if ((!neg && ft_strlen(str) > 9 && ft_strcmp("2147483647", str) < 0) ||
		(neg && ft_strlen(str) > 9 && ft_strcmp("2147483648", str) < 0))
		return (0);
	return (1);
}

int		args_to_list(int argc, char **argv, t_stack **s)
{
	int		i;

	if ((!ft_atoi(argv[0]) && ft_strcmp(argv[0], "0")) || !isint(argv[0]))
		return (0);
	*s = stacknew(ft_atoi(argv[0]));
	i = 0;
	while (++i < argc - 1)
	{
		if ((!ft_atoi(argv[i]) && ft_strcmp(argv[i], "0")) ||
			is_in_list(*s, ft_atoi(argv[i])) ||
			!isint(argv[i]))
		{
			stackdel(s);
			return (0);
		}
		stackpushback(ft_atoi(argv[i]), *s);
	}
	return (1);
}
