/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:25:13 by lrafael           #+#    #+#             */
/*   Updated: 2024/05/15 10:09:43 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_out(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if ((*(str + 1)) == '-' || (*(str + 1)) == '+')
		get_out("Error");
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			get_out("Error");
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (((result * sign) > 2147483647) || ((result * sign) < -2147483648))
		get_out("Error");
	return ((int)(result * sign));
}
