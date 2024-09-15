
#include "../incs/push_swap.h"

void	sa(t_stack **a, int fl)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*a = second;
	if (fl)
		ft_printf("sa\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*hold_a;
	t_stack	*first;
	t_stack	*holder;

	if (!(*b))
		return ;
	first = *b;
	hold_a = *a;
	holder = (*b)->next;
	first->next = hold_a;
	if (holder != NULL)
		holder->prev = NULL;
	if (hold_a != NULL)
		hold_a->prev = first;
	*b = holder;
	*a = first;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*hold_b;

	if (!(*a))
		return ;
	first = *a;
	hold_b = *b;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	first->next = hold_b;
	if (hold_b)
		hold_b->prev = first;
	*b = first;
	first->prev = NULL;
	ft_printf("pb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((!(*a) || !(*a)->next) || (!(*b) || !(*b)->next))
		return ;
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
