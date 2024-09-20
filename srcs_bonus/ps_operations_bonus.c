/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:29:39 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/16 12:16:47 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*a = second;
}

void	sb(t_stack **b)
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
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*hold_a;
	t_stack	*first;
	t_stack	*holder;

	if (!(*b))
		return ;
	first = *b;
	hold_a = *a;
	holder = (*b)->next;
	first->next = hold_a;
	if (holder != NULL)
		holder->prev = NULL;
	if (hold_a != NULL)
		hold_a->prev = first;
	*b = holder;
	*a = first;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*hold_b;

	if (!(*a))
		return ;
	first = *a;
	hold_b = *b;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	first->next = hold_b;
	if (hold_b)
		hold_b->prev = first;
	*b = first;
	first->prev = NULL;
}
