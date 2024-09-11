/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:02:23 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/11 08:13:11 by lrafael          ###   ########.fr       */
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

void	init_stack(t_stack **a, char **argv)
{
	int		i;
	int		j;
	char	**elem;

	if (argv[0][0] == '\0' || argv[0][0] == ' ')
		ft_print_error("Error");
	i = -1;
	while (argv[++i])
	{
		j = -1;
		elem = ft_split(argv[i], ' ');
		while (elem[++j])
			add_to_stack(a, ft_atoi(elem[j]));
		free_splited(elem);
	}
}
