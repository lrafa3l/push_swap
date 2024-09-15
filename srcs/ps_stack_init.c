/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:02:23 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/15 13:26:24 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_stack_init(t_stack **a, char **av)
{
	int		i;
	int		j;
	long	value;
	char	**elem;

	i = -1;
	while (av[++i])
	{
		j = 0;
		elem = ft_split(av[i], ' ');
		if (!elem)
			return ;
		while (elem[j])
		{
			value = ft_atol(elem[j], a, elem);
			if (value > INT_MAX || value < INT_MIN)
				ft_print_error(a, elem);
			if (ft_check_dup(*a, (int)value))
				ft_print_error(a, elem);
			ft_add_to_stack(a, (int)value);
			j++;
		}
		ft_free_split(elem);
	}
}

void	ft_add_to_stack(t_stack **a, int value)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!a)
		return ;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->cheapest = 0;
	node->next = NULL;
	node->value = value;
	if (!*a)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_elem(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

long	ft_atol(const char *s, t_stack **a, char **elem)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*s == 32 || (*s >= 6 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
		if (*s == '\0')
			ft_atol_error(a, elem);
	}
	while (*s)
	{
		if (!(*s >= 48 && *s <= 57))
			ft_atol_error(a, elem);
		nbr = (nbr * 10) + (*(s++) - 48);
	}
	return (nbr * sign);
}
