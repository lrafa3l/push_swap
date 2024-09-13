/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:02:23 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/13 14:46:08 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_to_stack(t_stack **a, int value)
{
	t_stack	*node;
	t_stack	*aux;

	node = create_node(value);
	if (!*a)
		*a = node;
	else
	{
		aux = last_elem(*a);
		node->prev = aux;
		aux->next = node;
	}
}

void	init_stack(t_stack **a, char **av)
{
	int		i;
	int		j;
	char	**elem;

	i = -1;
	while (av[++i])
	{
		j = -1;
		elem = ft_split(av[i], ' ');
		while (elem[++j])
			add_to_stack(a, ft_atoi(elem[j]));
		free_splited(elem);
	}
}
