/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:00:08 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/20 14:36:20 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_stack;

typedef struct s_operation
{
	char			*operation;
	char			*tmp_op;
}					t_operation;

/*Check*/
void				ft_check_error(int argc, char **argv);
int					ft_already_sorted(t_stack *stack);
int					ft_check_dup(t_stack *stack, int value);

/*Stack Init*/
void				ft_stack_init(t_stack **a, char **av);
void				ft_add_to_stack(t_stack **a, int value);
long				ft_atol(const char *s, t_stack **a, char **elem);

/*Stack Utils*/
t_stack				*ft_last_elem(t_stack *stack);
t_stack				*ft_big_node(t_stack *stack);
t_stack				*ft_small_node(t_stack *stack);
int					ft_stack_len(t_stack *stack);

/*Checker Init*/
void				ft_checker_init(t_stack **a, t_stack **b);
void				ft_execute(char *op, t_stack **a, t_stack **b);
void				ft_wrong_op(char *op, t_stack **a);

/*Clean Up*/
void				ft_print_error(t_stack **a, char **elem);
void				ft_atol_error(t_stack **a, char **elem);
void				ft_free_stack(t_stack **a);
void				ft_free_split(char **elem);

/*Operations*/
void				sa(t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

/*Rotate-operations*/
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

/*Reverse-Rot-operations+*/
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

#endif
