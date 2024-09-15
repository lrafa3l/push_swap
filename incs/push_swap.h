/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:15:31 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/15 09:22:43 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				up_middle;
	int				cheapest;

	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}					t_stack;

t_stack				*ft_last_elem(t_stack *stack);
t_stack				*ft_small_node(t_stack *stack);
t_stack				*ft_big_node(t_stack *stack);

void				ft_stack_init(t_stack **a, char **av);
void				ft_add_to_stack(t_stack **a, int value);
void				ft_print_error(t_stack **a, char **elem);
void				ft_free_stack(t_stack **a);
void				ft_free_split(char **elem);
void				ft_atol_error(t_stack **a);

void				sorting_three(t_stack **stack);

int					ft_check_dup(t_stack *stack, int value);
int					ft_already_sorted(t_stack *stack);
int					ft_stack_len(t_stack *stack);

long				ft_atol(const char *s, t_stack **a);

/*Operations*/
void				sa(t_stack **a, int fl);
void				sb(t_stack **b, int fl);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				ra(t_stack **a, int fl);
void				rb(t_stack **b, int fl);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a, int fl);
void				rrb(t_stack **b, int fl);
void				rrr(t_stack **a, t_stack **b);

#endif
