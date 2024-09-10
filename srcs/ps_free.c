/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:48:15 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/10 13:48:24 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	free_splited(char **elems)
{
	int	i;

	i = -1;
	if (!elems)
		return ;
	while (elems[++i])
		free(elems[i]);
	free(elems);
}
