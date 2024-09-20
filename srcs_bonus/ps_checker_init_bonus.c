/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_init_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:16:46 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/19 18:51:38 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_execute(char *op, t_stack **a, t_stack **b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b);
	else
		ft_wrong_op(op, a);
}

void	ft_check_null(char *op, t_stack **a, t_stack **b)
{
	if (!op)
	{
		if (ft_already_sorted(*a) && *b == NULL)
		{
			if (a)
				ft_free_stack(a);
			free(op);
			get_next_line(-1, 1);
			write(1, "OK\n", 3);
			exit(0);
		}
		else
		{
			if (a)
				ft_free_stack(a);
			free(op);
			get_next_line(-1, 1);
			write(1, "OK\n", 3);
			exit(0);
		}
		return ;
	}
}

void	ft_check_space_in(t_stack **a)
{
	ft_free_stack(a);
	get_next_line(-1, 1);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_checker_init(t_stack **a, t_stack **b)
{
	t_operation	op;

	op.operation = get_next_line(STDIN_FILENO, 0);
	ft_check_null(op.operation, a, b);
	while (op.operation)
	{
		ft_execute(op.operation, a, b);
		free(op.operation);
		op.operation = get_next_line(STDIN_FILENO, 0);
	}
	free(op.operation);
	if (ft_already_sorted(*a) && *b == NULL)
		write(1, "OK\n", 3);
	else if (!ft_already_sorted(*a) && *b != NULL)
		write(1, "KO\n", 3);
}
