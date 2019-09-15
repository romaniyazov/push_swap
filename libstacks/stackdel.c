/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:27:41 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 19:27:56 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	stackdel(t_stack **s)
{
	t_stack		*tmp;
	t_stack		*ss;

	if (!*s)
		return ;
	ss = *s;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	ss = NULL;
}
