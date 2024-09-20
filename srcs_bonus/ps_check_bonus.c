/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:23:48 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/19 18:51:30 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

static int	ft_invalid(char *str)
{
	if (str == NULL || *str == '\0')
		return (1);
	while (*str)
	{
		if (!(*str == 32 || (*str >= 7 && *str <= 13)))
			return (0);
		str++;
	}
	return (1);
}

void	ft_check_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_invalid(argv[i]))
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		i++;
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
