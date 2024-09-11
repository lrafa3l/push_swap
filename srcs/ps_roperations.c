/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_roperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:29:53 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/11 08:13:59 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ra(t_stack **a, int fl)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*secnd;

	first = *a;
	secnd = (*a)->next;
	last = last_elem(*a);
	if (*a != NULL && (*a)->next != NULL)
	{
		first->next = NULL;
		secnd->prev = NULL;
		last->next = first;
		first->prev = last;
		*a = secnd;
		if (fl)
			ft_printf("ra\n");
	}
}

void	rb(t_stack **b, int fl)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*secnd;

	first = *b;
	secnd = (*b)->next;
	last = last_elem(*b);
	if (*b != NULL && (*b)->next != NULL)
	{
		first->next = NULL;
		secnd->prev = NULL;
		last->next = first;
		first->prev = last;
		*b = secnd;
		if (fl)
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

void	rra(t_stack **a, int fl)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	last = last_elem(*a);
	if (*a != NULL && (*a)->next != NULL)
	{
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*a = last;
		if (fl)
			ft_printf("rra\n");
	}
}

void	rrb(t_stack **b, int fl)
{
	t_stack	*first;
	t_stack	*last;

	first = *b;
	last = last_elem(*b);
	if (*b != NULL && (*b)->next != NULL)
	{
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*b = last;
		if (fl)
			ft_printf("rrb\n");
	}
}
