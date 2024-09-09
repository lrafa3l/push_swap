/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_and_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:23:48 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/09 17:23:50 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	already_sorted(t_stack *a)
{
	int x;

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

int double_elem(t_stack *a)
{
    int x;

    x = a->value;
    while (a)
    {
        if (!a->next)
            return (0);
        if (x == a->next->value)
            return (1);
        a = a->next;
    }
    return (0);
}