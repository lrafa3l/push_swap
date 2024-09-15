/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils+.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:30:06 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/15 09:21:30 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_print_error(t_stack **a, char **elem)
{
	ft_free_stack(a);
	if (elem != NULL)
		ft_free_split(elem);
	ft_printf("Error\n");
	exit(1);
}

void	ft_atol_error(t_stack **a)
{
	ft_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
