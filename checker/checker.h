/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:11:00 by adavis            #+#    #+#             */
/*   Updated: 2019/09/08 22:00:25 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
# define CHECKER

# include "libft.h"
# include "stacks.h"

# define INSTRUCTIONS (const char*[11]){ "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr" }

int		args_to_list(int argc, char **argv, t_stack **s);
void	print_stacks(t_stack *a, t_stack *b);

#endif
