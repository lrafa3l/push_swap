/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:12:08 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/13 14:45:41 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sorting_three(t_stack **stack)
{
	t_stack	*big;

	big = big_node(*stack);
	if (big->value == (*stack)->value)
		ra(stack, 1);
	else if (big->value == (*stack)->next->value)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}

void	sorting(t_stack **a, t_stack **b)
{
	int	stack_size;

	stack_size = count_elem(*a);
	while (stack_size-- > 3)
		pb(a, b);
	sorting_three(a);
	while (*b)
	{
		process_stack(*a, *b);
		get_ready_to_push(a, b);
	}
	small_node_on_top(a);
}

void	process_stack(t_stack *a, t_stack *b)
{
	put_index(a);
	put_index(b);
	find_target(a, b);
	find_cost(a, b);
	find_cheapest(b);
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target;
	long	best_target;

	while (b)
	{
		best_target = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < best_target)
			{
				best_target = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_target == LONG_MAX)
			b->target = small_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	find_cost(t_stack *a, t_stack *b)
{
	int	stack_size_a;
	int	stack_size_b;

	stack_size_a = count_elem(a);
	stack_size_b = count_elem(b);
	while (b)
	{
		b->cost = b->index;
		if (!(b->up_middle))
			b->cost = stack_size_b - (b->index);
		if (b->target->up_middle)
			b->cost += b->target->index;
		else
			b->cost += stack_size_a - (b->target->index);
		b = b->next;
	}
}
