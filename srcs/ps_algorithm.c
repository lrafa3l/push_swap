/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:12:08 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/11 13:32:45 by lrafael          ###   ########.fr       */
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


	// int		i;
	// t_stack	*tmp1;
	// i = 0;
	stack_size = count_elem(*a);
	while (stack_size-- > 3)
		pb(a, b);
	sorting_three(a);
	while (*b)
	{
		// i++;
		process_stack(*a, *b);
		// if (i == 1)
		// 	break ;
		get_ready_to_push(a, b);
	}
	small_node_on_top(a);
	// tmp1 = *b;
	// while (tmp1 != NULL)
	// {
	// 	ft_printf("Index: %d Value: %d Target: %d Cost: %d\n\n", tmp1->index,
	// 		tmp1->value, tmp1->target->value, tmp1->cost);
	// 	if (tmp1->cheapest == 1)
	// 		ft_printf("Cheapest: %d\n", tmp1->value);
	// 	tmp1 = tmp1->next;
	// }
	if (already_sorted(*a))
		ft_printf("\nDone\n");
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

void	find_cheapest(t_stack *stack)
{
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			stack->cheapest = 1;
			cheapest_value = stack->cost;
		}
		else
			stack->cheapest = 0;
		stack = stack->next;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	get_ready_to_push(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*b);
	while (*a != cheap->target && cheap != *b)
	{
		if (cheap->target->up_middle && cheap->target->up_middle)
			rr(a, b);
		else
			rrr(a, b);
	}
	while (cheap != *b)
	{
		if (cheap->up_middle)
			rb(b, 1);
		else
			rrb(b, 1);
	}
	while (cheap->target != *a)
	{
		if (cheap->target->up_middle)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pa(a, b);
}

void	small_node_on_top(t_stack **a)
{
	t_stack *min_node;

	min_node = small_node(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->up_middle)
			ra(a, 1);
		else
			rra(a, 1);
	}
}