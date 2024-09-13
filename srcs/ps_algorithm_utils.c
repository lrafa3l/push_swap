
#include "../incs/push_swap.h"

void	put_index(t_stack *stack)
{
	int	index;
	int	up_middle;

	index = 0;
	up_middle = count_elem(stack) / 2;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = index;
		if (index <= up_middle)
			stack->up_middle = 1;
		else
			stack->up_middle = 0;
		stack = stack->next;
		index++;
	}
}

void	find_cheapest(t_stack *stack)
{
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			stack->cheapest = 1;
			cheapest_value = stack->cost;
		}
		else
			stack->cheapest = 0;
		stack = stack->next;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	get_ready_to_push(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*b);
	while (*a != cheap->target && cheap != *b)
	{
		if (cheap->target->up_middle && cheap->target->up_middle)
			rr(a, b);
		else
			rrr(a, b);
	}
	while (cheap != *b)
	{
		if (cheap->up_middle)
			rb(b, 1);
		else
			rrb(b, 1);
	}
	while (cheap->target != *a)
	{
		if (cheap->target->up_middle)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pa(a, b);
}

void	small_node_on_top(t_stack **a)
{
	t_stack	*min_node;

	min_node = small_node(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->up_middle)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
