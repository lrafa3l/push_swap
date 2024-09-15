/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils+.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:57:37 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/15 13:26:04 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	process_stack_b(t_stack *a, t_stack *b)
{
	def_index(a);
	def_index(b);
	def_target_b(a, b);
}

void	def_target_b(t_stack *a, t_stack *b)
{
	long	target;
	t_stack	*curr_a;
	t_stack	*target_node;

	while (b)
	{
		target = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < target)
			{
				target = curr_a->value;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (target == LONG_MAX)
			b->target = ft_small_node(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	rotate(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	def_index(*a);
	def_index(*b);
}

void	reverse_rotate(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	def_index(*a);
	def_index(*b);
}

void	transfer_b_to_a(t_stack **a, t_stack **b)
{
	get_ready(a, (*b)->target, 'a');
	pa(a, b);
}
