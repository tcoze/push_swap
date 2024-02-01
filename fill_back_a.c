/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_back_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:32:33 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/23 01:32:33 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_turn_a(struct s_s *a)
{
	int	i;

	i = 0;
	while (a->stack[i] < a->stack[i + 1] && i < a->size - 2)
		i++;
	if (i < a->size / 2)
	{
		while (a->stack[0] > a->stack[a->size - 1] && i++ < a->size - 1)
			if (ra (a) == -1)
				return (-1);
	}
	if (i >= a->size / 2)
	{
		while (a->stack[0] > a->stack[a->size - 1] && i++ < a->size - 1)
			if (rra (a) == -1)
				return (-1);
	}
	return (0);
}

static int	ft_check_define_case_b(struct s_s *a, struct s_s *b, int i)
{
	if (b->stack[0] > a->stack[0] && b->stack[0] > a->stack[a->size - 1]
		&&a->stack[0] < a->stack[a->size - 1])
	{
		if (pa (a, b) == -1)
			return (-1);
		i = 1;
	}
	if (b->stack[0] > a->stack[0] && b->stack[0] > a->stack[a->size - 1]
		&& a->stack[0] > a->stack[a->size - 1])
	{
		if (rra (a) == -1)
			return (-1);
		i = 1;
	}
	if (i == 0)
		return (0);
	return (1);
}

static int	ft_check_define_case_a(struct s_s *a, struct s_s *b, int i)
{
	if (b->stack[0] < a->stack[a->size - 1] && b->stack[0] > a->stack[0]
		&& a->stack[0] < a->stack[a->size - 1])
	{
		if (rra (a) == -1)
			return (-1);
		i = 1;
	}
	if (b->stack[0] < a->stack[0] && b->stack[0] > a->stack[a->size - 1])
	{
		if (pa (a, b) == -1)
			return (-1);
		i = 1;
	}
	if (b->stack[0] < a->stack[0] && b->stack[0] < a->stack[a->size - 1]
		&& a->stack[0] > a->stack[a->size - 1])
	{
		if (rra(a) == -1)
			return (-1);
		i = 1;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	ft_fill_back_a(struct s_s *a, struct s_s *b)
{
	int	a_case;
	int	b_case;
	int	i;

	i = 0;
	while (b->size > 0)
	{
		a_case = ft_check_define_case_a(a, b, i);
		if (a_case == -1)
			return (-1);
		b_case = ft_check_define_case_b(a, b, i);
		if (b_case == -1)
			return (-1);
		if (a_case == 0 && b_case == 0)
			if (pa(a, b) == -1)
				return (-1);
	}
	if (ft_turn_a(a) == -1)
		return (-1);
	return (0);
}
