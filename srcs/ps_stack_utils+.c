/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils+.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:30:06 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/15 13:26:48 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	def_index(t_stack *stack)
{
	int	index;
	int	mid;

	index = 0;
	if (!stack)
		return ;
	mid = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= mid)
			stack->up_middle = 1;
		else
			stack->up_middle = 0;
		stack = stack->next;
		++index;
	}
}

void	ft_print_error(t_stack **a, char **elem)
{
	ft_free_stack(a);
	if (elem != NULL)
		ft_free_split(elem);
	ft_printf("Error\n");
	exit(1);
}

void	ft_atol_error(t_stack **a, char **elem)
{
	ft_free_stack(a);
	if (elem != NULL)
		ft_free_split(elem);
	ft_printf("Error\n");
	exit(1);
}
