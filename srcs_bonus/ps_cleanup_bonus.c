/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cleanup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:48:15 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/16 14:09:54 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

void	ft_print_error(t_stack **a, char **elem)
{
	ft_free_stack(a);
	if (elem != NULL)
		ft_free_split(elem);
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_atol_error(t_stack **a, char **elem)
{
	ft_free_stack(a);
	if (elem != NULL)
		ft_free_split(elem);
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

void	ft_free_split(char **elem)
{
	int	i;

	i = 0;
	if (!elem)
		return ;
	while (elem[i])
		free(elem[i++]);
	free(elem);
	elem = NULL;
}
