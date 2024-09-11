/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:10:18 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/11 13:33:32 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*tmp;

	// t_stack	*b;
	a = NULL;
	// b = NULL;
	if (argc < 2)
		return (1);
	init_stack(&a, argv + 1);
	check_stack(a);
	sorting_three(&a);
	//ra(&a, 1);
	tmp = a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
