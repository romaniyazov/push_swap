/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:11:00 by adavis            #+#    #+#             */
/*   Updated: 2019/09/07 16:38:53 by adavis           ###   ########.fr       */
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

/*
** Basic stack methods
*/
t_stack	*stacknew(int nbr);
void	stackpush(int nbr, t_stack **s);
void	stackpushback(int nbr, t_stack *s);
int		stackpoplast(t_stack *s);
int		stackpopfirst(t_stack **s);
void	stackdel(t_stack **s);

/*
** push_swap operations
*/
void	push(t_stack **a, t_stack **b);
void	swap(t_stack **s);
void	rotate(t_stack **s);
void	reverse_rotate(t_stack **s);

#endif
