/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_entry.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 05:07:52 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/22 05:07:52 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_int_min(char *argv)
{
	if (ft_strcmp (argv, "-2147483648") == 0)
		return (-2147483648);
	else
		return (-1);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_check_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

static int	ft_fill_num(char *argv[], int i, int j)
{
	int	temp;

	temp = 0;
	while (argv[i][++j - 1])
	{
		if (ft_isdigit(argv[i][j - 1]) == 1)
			temp = temp * 10 + (argv[i][j - 1] - '0');
		if (temp < 0)
			return (ft_check_int_min(argv[i]));
		if (ft_isdigit(argv[i][j - 1]) == 0)
			return (-1);
	}
	return (temp);
}

int	ft_check_entry(char *argv[], struct s_s a)
{
	int	i;
	int	j;
	int	temp;
	int	size;

	size = 0;
	i = 0;
	while (argv[++i])
	{
		temp = 0;
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			if (ft_isdigit (argv[i][j + 1]) == 0)
				return (-1);
			j++;
		}
		temp = ft_fill_num(argv, i, j);
		if (temp == -1)
			return (-1);
		a.stack[i - 1] = temp * ft_check_sign(argv[i][0]);
		size++;
	}
	return (size);
}
