
#include "../incs/push_swap.h"

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

void	ft_free_split(char **elem)
{
	int	i;

	i = 0;
	if (!elem)
		return ;
	while (elem[i])
		free(elem[i++]);
	free(elem);
	elem = NULL;
}
