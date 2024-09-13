/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:10:18 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/13 14:46:16 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	check_space(av);
	init_stack(&a, av + 1);
	check_stack(a);
	if (count_elem(a) == 2)
		sa(&a, 1);
	else if (count_elem(a) == 3)
		sorting_three(&a);
	else
		sorting(&a, &b);
	return (0);
}
