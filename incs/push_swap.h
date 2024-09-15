/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:15:31 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/15 14:54:08 by lrafael          ###   ########.fr       */
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

/*Check*/
int					ft_check_dup(t_stack *stack, int value);
int					ft_already_sorted(t_stack *stack);
void				ft_check_space(char **av);

/*Free*/
void				ft_free_stack(t_stack **a);
void				ft_free_split(char **elem);

/*Sorting*/
void				ft_sorting_three(t_stack **stack);
void				ft_sorting(t_stack **a, t_stack **b);
void				get_ready(t_stack **stack, t_stack *tail, char stack_n);
void				small_node_on_top(t_stack **a);

/*Stack Init*/
void				ft_stack_init(t_stack **a, char **av);
void				ft_add_to_stack(t_stack **a, int value);
long				ft_atol(const char *s, t_stack **a, char **elem);

/*Stack Utils*/
t_stack				*ft_last_elem(t_stack *stack);
t_stack				*ft_big_node(t_stack *stack);
t_stack				*ft_small_node(t_stack *stack);
t_stack				*get_cheapest(t_stack *stack);
int					ft_stack_len(t_stack *stack);

/*Stack Utils+*/
void				ft_print_error(t_stack **a, char **elem);
void				ft_atol_error(t_stack **a, char **elem);
void				def_index(t_stack *stack);

/*Operations*/
void				sa(t_stack **a, int fl);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/*R-operations*/
void				ra(t_stack **a, int fl);
void				rb(t_stack **b, int fl);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, int fl);
void				rrb(t_stack **b, int fl);

/*Sorting Utils*/
void				process_stack_a(t_stack *a, t_stack *b);
void				def_target_a(t_stack *a, t_stack *b);
void				def_cost(t_stack *a, t_stack *b);
void				def_cheapest(t_stack *stack);
void				transfer_a_to_b(t_stack **a, t_stack **b);

/*Sorting Utils+*/
void				process_stack_b(t_stack *a, t_stack *b);
void				def_target_b(t_stack *a, t_stack *b);
void				rotate(t_stack **a, t_stack **b, t_stack *cheapest);
void				reverse_rotate(t_stack **a, t_stack **b, t_stack *cheapest);
void				transfer_b_to_a(t_stack **a, t_stack **b);

#endif
