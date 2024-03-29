/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:01:43 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 20:02:30 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_sorted(t_stack *s)
{
	while (s->next)
	{
		if (s->next->nbr < s->nbr)
			return (0);
		s = s->next;
	}
	return (1);
}
