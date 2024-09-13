/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:15:31 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/13 14:46:58 by lrafael          ###   ########.fr       */
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

/*Stack Utils*/
t_stack				*create_node(int value);
t_stack				*big_node(t_stack *stack);
t_stack				*small_node(t_stack *stack);
t_stack				*last_elem(t_stack *stack);
t_stack				*get_cheapest(t_stack *stack);

int					count_elem(t_stack *stack);
int					double_elem(t_stack *a);
int					already_sorted(t_stack *a);

/*Validations*/
void				check_space(char **av);
void				init_stack(t_stack **a, char **argv);
void				check_stack(t_stack *a);
void				add_to_stack(t_stack **a, int value);

/*Algorithm abd Utils*/
void				sorting_three(t_stack **stack);
void				sorting(t_stack **a, t_stack **b);
void				process_stack(t_stack *a, t_stack *b);
void				put_index(t_stack *stack);
void				find_target(t_stack *a, t_stack *b);
void				find_cost(t_stack *a, t_stack *b);
void				find_cheapest(t_stack *stack);
void				get_ready_to_push(t_stack **a, t_stack **b);
void				small_node_on_top(t_stack **a);
void				free_splited(char **elems);

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

/*Others*/
void				ft_print_error(char *msg);

#endif
