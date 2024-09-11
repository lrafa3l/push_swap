/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:29:39 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/11 13:35:48 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sa(t_stack **a, int fl)
{
	t_stack	*first;
	t_stack	*secnd;

	if (*a != NULL && (*a)->next != NULL)
	{
		first = *a;
		secnd = (*a)->next;
		first->next = NULL;
		first->next = secnd->next;
		if (secnd->next != NULL)
			secnd->next->prev = first;
		secnd->next = first;
		first->prev = secnd;
		secnd->prev = NULL;
		*a = secnd;
		if (fl)
			ft_printf("sa\n");
	}
}

void	sb(t_stack **b, int fl)
{
	t_stack	*first;
	t_stack	*secnd;

	if (*b != NULL && (*b)->next != NULL)
	{
		first = *b;
		secnd = (*b)->next;
		first->next = NULL;
		first->next = secnd->next;
		if (secnd->next != NULL)
			secnd->next->prev = first;
		secnd->next = first;
		first->prev = secnd;
		secnd->prev = NULL;
		*b = secnd;
		if (fl)
			ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*secnd;

	if (*b != NULL)
	{
		first = *b;
		secnd = (*b)->next;
		first->next = NULL;
		if (secnd != NULL)
			secnd->prev = NULL;
		first->next = *a;
		if (*a != NULL)
			(*a)->prev = first;
		*a = first;
		*b = secnd;
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*secnd;

	if (*a != NULL)
	{
		first = *a;
		secnd = (*a)->next;
		first->next = NULL;
		if (secnd != NULL)
			secnd->prev = NULL;
		first->next = *b;
		if (*b != NULL)
			(*b)->prev = first;
		*b = first;
		*a = secnd;
		ft_printf("pb\n");
	}
}
