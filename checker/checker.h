/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:11:00 by adavis            #+#    #+#             */
/*   Updated: 2019/09/06 18:50:57 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
# define CHECKER

# include "libft.h"

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

int		main(int argc, char** argv);
t_stack	*stacknew();
t_stack	*stackpush(int nbr, t_stack *s);
void	stackpushback(int nbr, t_stack *s);

#endif
