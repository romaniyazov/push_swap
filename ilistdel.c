/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilistdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:47:43 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 22:48:00 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ilistdel(t_ilist **s)
{
	t_ilist		*tmp;
	t_ilist		*ss;

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
