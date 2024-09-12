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
	while (count_elem(*a) > 3)
	{
		process_stack(*a, *b);
	}
}

void	process_stack(t_stack *a, t_stack *b)
{
	(void)*b;
	put_index(a);
}