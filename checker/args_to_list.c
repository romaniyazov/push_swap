/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:47:18 by adavis            #+#    #+#             */
/*   Updated: 2019/09/08 20:02:19 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		args_to_list(int argc, char **argv, t_stack **s)
{
	int		i;

	if (!ft_atoi(argv[1]) && (ft_strlen(argv[1]) != 1 || argv[1][0] != '0'))
		return (0);
	*s = stacknew(ft_atoi(argv[1]));
	i = 1;
	while (++i < argc)
	{
		if (!ft_atoi(argv[i]) &&
							(ft_strlen(argv[i]) != 1 || argv[i][0] != '0'))
		{
			stackdel(s);
			return (0);
		}
		stackpushback(ft_atoi(argv[i]), *s);
	}
	return (1);
}
