/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:30:06 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/13 14:46:38 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_stack	*last_elem(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*big_node(t_stack *stack)
{
	t_stack	*big;
	t_stack	*tmp;

	big = stack;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->value > big->value)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

t_stack	*small_node(t_stack *stack)
{
	t_stack	*small;
	t_stack	*tmp;

	small = stack;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->value < small->value)
			small = tmp;
		tmp = tmp->next;
	}
	return (small);
}

int	count_elem(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	ft_print_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}
