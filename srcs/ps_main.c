/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:10:18 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/09 18:27:33 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*tmp;
	//t_stack	*b;

	//t_stack	*tmp1;

	a = NULL;
	//b = NULL;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&a, argv);
	}
	else
		init_stack(&a, argv + 1);
	if (already_sorted(a))
		return (0);
	if (double_elem(a) == 1)
		return (0);
	ra(&a, 1);
	tmp = a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
