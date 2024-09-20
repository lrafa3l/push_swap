/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_roperations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:29:53 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/19 18:52:20 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	last = ft_last_elem(*a);
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*a = last;
}

void	rrb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	first = *b;
	last = ft_last_elem(*b);
	if (*b != NULL && (*b)->next != NULL)
	{
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*b = last;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((!(*a) || !(*a)->next) || (!(*b) || !(*b)->next))
		return ;
	rra(a);
	rrb(b);
}
