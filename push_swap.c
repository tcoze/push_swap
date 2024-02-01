/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:58:41 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/24 11:41:59 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_free(struct s_s a, struct s_s b, int i)
{
	free(a.stack);
	free(b.stack);
	if (i == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	else
		return (0);
}

static int	ft_check_a_sort(struct s_s a)
{
	int	i;

	i = 0;
	while (i < a.size - 1)
	{
		if (a.stack[i] < a.stack[i + 1])
			i++;
		else
			return (-1);
	}
	return (i);
}

static int	ft_strcmp_double(struct s_s a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.size - 1)
	{
		j = i + 1;
		while (j < a.size)
		{
			if (a.stack[i] == a.stack[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_case_argc(int argc, struct s_s a, struct s_s b)
{
	if (argc <= 4)
		if (alg_inferior(&a) == -1)
			return (-1);
	if (argc == 5)
		if (pb(&a, &b) == -1)
			return (-1);
	if (argc > 5)
	{
		if (pb(&a, &b) == -1)
			return (-1);
		if (pb(&a, &b) == -1)
			return (-1);
		if (b.stack[0] < b.stack[1])
			if (sb(&b) == -1)
				return (-1);
	}
	while (a.size > 3)
		if (alg_superior (&a, &b) == -1)
			return (-1);
	if (alg_inferior (&a) == -1)
		return (-1);
	while (b.size > 0)
		if (ft_fill_back_a(&a, &b) == -1)
			return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a.stack = malloc(sizeof(int) * (argc - 1));
	if (!a.stack)
		return (-1);
	b.stack = malloc(sizeof(int) * (argc - 1));
	if (!b.stack)
		return (free(a.stack), -1);
	if (ft_check_entry(argv, a) == -1)
		return (ft_free(a, b, -1));
	a.size = argc - 1;
	b.size = 0;
	if (ft_check_a_sort(a) != -1)
		return (ft_free(a, b, 0));
	if (ft_strcmp_double(a) == -1 || argc == 1)
		return (ft_free(a, b, -1));
	if (argc >= 2)
		if (ft_case_argc(argc, a, b) == -1)
			return (ft_free (a, b, -1));
	return (ft_free(a, b, 0));
}
