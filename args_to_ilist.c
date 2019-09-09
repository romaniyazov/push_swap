/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_ilist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:47:18 by adavis            #+#    #+#             */
/*   Updated: 2019/09/09 19:23:25 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		args_to_ilist(int argc, char **argv, t_ilist **s)
{
	int		i;

	if (!ft_atoi(argv[1]) && ft_strcmp(argv[1], "0"))
		return (0);
	*s = ilistnew(ft_atoi(argv[1]), 0);
	i = 1;
	while (++i < argc)
	{
		if (!ft_atoi(argv[i]) && ft_strcmp(argv[i], "0"))
		{
			ilistdel(s);
			return (0);
		}
		ilistpushback(ft_atoi(argv[i]), 0, *s);
	}
	return (1);
}
