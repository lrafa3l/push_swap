/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:57:31 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/20 14:35:49 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	process_stack_a(t_stack *a, t_stack *b)
{
	def_index(a);
	def_index(b);
	def_target_a(a, b);
	def_cost(a, b);
	def_cheapest(a);
}

void	def_target_a(t_stack *a, t_stack *b)
{
	long	target;
	t_stack	*curr_b;
	t_stack	*target_node;

	while (a)
	{
		target = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > target)
			{
				target = curr_b->value;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (target == LONG_MIN)
			a->target = ft_big_node(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	def_cost(t_stack *a, t_stack *b)
{
	t_cost	cst;

	cst.a_len = ft_stack_len(a);
	cst.b_len = ft_stack_len(b);
	while (a)
	{
		cst.max_rot = a->target->index;
		if (a->index > a->target->index)
			cst.max_rot = a->index;
		cst.total_cost = cst.max_rot;
		cst.max_rrot = cst.b_len - a->target->index;
		if (cst.a_len - a->index > cst.b_len - a->target->index)
			cst.max_rrot = cst.a_len - a->index;
		if (cst.max_rrot < cst.total_cost)
			cst.total_cost = cst.max_rrot;
		cst.ra_rrb = a->index + (cst.b_len - a->target->index);
		if (cst.ra_rrb < cst.total_cost)
			cst.total_cost = cst.ra_rrb;
		cst.rra_rb = (cst.a_len - a->index) + a->target->index;
		if (cst.rra_rb < cst.total_cost)
			cst.total_cost = cst.rra_rb;
		a->cost = cst.total_cost;
		a = a->next;
	}
}

void	def_cheapest(t_stack *stack)
{
	long	cheap;
	t_stack	*cheap_node;

	if (!stack)
		return ;
	cheap = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheap)
		{
			cheap = stack->cost;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	cheap_node->cheapest = 1;
}

void	transfer_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*a);
	if (cheap->up_middle && cheap->target->up_middle)
		rotate(a, b, cheap);
	else if (!(cheap->up_middle) && !(cheap->target->up_middle))
		reverse_rotate(a, b, cheap);
	get_ready(a, cheap, 'a');
	get_ready(b, cheap->target, 'b');
	pb(a, b);
}
