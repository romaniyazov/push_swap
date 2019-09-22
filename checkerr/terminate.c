/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:28:24 by adavis            #+#    #+#             */
/*   Updated: 2019/09/21 17:28:52 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	terminate(t_stack **a, t_stack **b)
{
	stackdel(a);
	stackdel(b);
	write(2, "Error\n", 6);
	exit(0);
}