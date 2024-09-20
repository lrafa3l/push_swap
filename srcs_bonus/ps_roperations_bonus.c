/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_roperations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:29:53 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/19 18:52:37 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*taker;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	taker = (*a)->next;
	last = ft_last_elem(*a);
	first->next = NULL;
	taker->prev = NULL;
	last->next = first;
	first->prev = last;
	*a = taker;
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*secnd;

	first = *b;
	secnd = (*b)->next;
	last = ft_last_elem(*b);
	if (*b != NULL && (*b)->next != NULL)
	{
		first->next = NULL;
		secnd->prev = NULL;
		last->next = first;
		first->prev = last;
		*b = secnd;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	if ((!(*a) || !(*a)->next) || (!(*b) || !(*b)->next))
		return ;
	ra(a);
	rb(b);
}
