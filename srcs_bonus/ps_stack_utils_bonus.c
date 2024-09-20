/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:30:06 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/16 14:10:19 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

t_stack	*ft_last_elem(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_big_node(t_stack *stack)
{
	t_stack	*big;

	big = stack;
	if (!stack)
	{
		return (NULL);
	}
	while (stack)
	{
		if (big->value < stack->value)
			big = stack;
		stack = stack->next;
	}
	return (big);
}

t_stack	*ft_small_node(t_stack *stack)
{
	t_stack	*small;

	small = stack;
	if (!stack)
	{
		return (NULL);
	}
	while (stack)
	{
		if (small->value > stack->value)
			small = stack;
		stack = stack->next;
	}
	return (small);
}

int	ft_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
