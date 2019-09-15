/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:11:00 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 20:02:02 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "stacks.h"

# define I (char*[]){"sa","sb","ss","pa","pb","ra","rb","rr","rra","rrb","rrr"}

int		args_to_list(int argc, char **argv, t_stack **s);
void	print_stacks(t_stack *a, t_stack *b);
int		is_sorted(t_stack *s);

#endif
