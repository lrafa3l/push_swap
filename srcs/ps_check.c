/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:23:48 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/15 09:20:20 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_already_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (0);
	while (stack->next)
	{
		tmp = stack;
		if (tmp->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_check_dup(t_stack *stack, int value)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (value == stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
