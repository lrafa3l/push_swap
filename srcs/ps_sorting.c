
#include "../incs/push_swap.h"

void	ft_sorting_three(t_stack **stack)
{
	t_stack	*big;

	big = ft_big_node(*stack);
	if (big->value == (*stack)->value)
		ra(stack, 1);
	else if (big->value == (*stack)->next->value)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}

void	ft_sorting(t_stack **a, t_stack **b)
{
	int	stack_len;

	stack_len = ft_stack_len(*a);
	if (stack_len-- > 3 && !ft_already_sorted(*a))
		pb(a, b);
	if (stack_len-- > 3 && !ft_already_sorted(*a))
		pb(a, b);
	while (stack_len-- > 3 && !ft_already_sorted(*a))
	{
		process_stack_a(*a, *b);
		transfer_a_to_b(a, b);
	}
	ft_sorting_three(a);
	while (*b)
	{
		process_stack_b(*a, *b);
		transfer_b_to_a(a, b);
	}
	def_index(*a);
	small_node_on_top(a);
}

void	get_ready(t_stack **stack, t_stack *tail, char stack_n)
{
	while (*stack != tail)
	{
		if (stack_n == 'a')
		{
			if (tail->up_middle)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_n == 'b')
		{
			if (tail->up_middle)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	small_node_on_top(t_stack **a)
{
	t_stack	*small;

	small = ft_small_node(*a);
	while (small != *a)
	{
		if (small->up_middle)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
