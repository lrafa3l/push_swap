/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:45:27 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/20 14:34:37 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

void	ft_wrong_op(char *op, t_stack **a)
{
	if (a)
		ft_free_stack(a);
	free(op);
	op = get_next_line(STDIN_FILENO, 1);
	free(op);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_clean(char *op, t_stack **a)
{
	if (a)
		ft_free_stack(a);
	free(op);
	get_next_line(-1, 1);
	write(2, "Error\n", 6);
	exit(1);
}
