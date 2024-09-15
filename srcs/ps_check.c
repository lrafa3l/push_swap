/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:23:48 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/15 14:53:57 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_check_space(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (av[i])
	{
		j = 0;
		k = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ')
				k++;
			j++;
		}
		i++;
	}
	if (k == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

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
