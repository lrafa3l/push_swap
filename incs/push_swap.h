/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:15:31 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/09 17:00:22 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_stack;

t_stack				*create_node(int value);
t_stack				*last_elem(t_stack *stack);

int					count_elem(t_stack *stack);
int					already_sorted(t_stack *a);
int					double_elem(t_stack *a);

void				init_stack(t_stack **a, char **argv);
void				check_stack(t_stack *a);
void				add_to_stack(t_stack **a, int value);
void				free_splited(char **elems);
void				ft_print_error(char *msg);

/*Operations*/
void				sa(t_stack **a, int fl);
void				sb(t_stack **b, int fl);
void				ss(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				ra(t_stack **a, int fl);
void				rb(t_stack **b, int fl);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a, int fl);
void				rrb(t_stack **b, int fl);
void				rrr(t_stack **a, t_stack **b);

#endif
