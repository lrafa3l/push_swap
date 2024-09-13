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

int	main(int argc, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	init_stack(&a, av + 1);
	check_stack(a);
	if (count_elem(a) == 2)
		sa(&a, 1);
	else if (count_elem(a) == 3)
		sorting_three(&a);
	else
		sorting(&a, &b);
	tmp = a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
	t_stack *tmp1 = b;
	while (tmp1 != NULL)
	{
		ft_printf("%d\n", tmp1->value);
		tmp1 = tmp1->next;
	}
	return (0);
}
