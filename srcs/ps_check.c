/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:23:48 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/11 13:32:53 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	already_sorted(t_stack *a)
{
	int	x;

	if (!a)
		return (1);
	x = a->value;
	while (a)
	{
		if (x > a->value)
			return (0);
		x = a->value;
		a = a->next;
	}
	return (1);
}

int	double_elem(t_stack *a)
{
	t_stack	*tmp;

	if (a == NULL)
		return (0);
	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

void	check_stack(t_stack *a)
{
	if (double_elem(a) == 1)
		ft_print_error("Error");
	if (already_sorted(a))
		exit(0);
}
