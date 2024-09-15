
#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	ft_check_space(argv);
	ft_stack_init(&a, argv + 1);
	if (!ft_already_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, 1);
		else if (ft_stack_len(a) == 3)
			ft_sorting_three(&a);
		else
			ft_sorting(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
