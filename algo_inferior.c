/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_inferior.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:51:53 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/16 03:10:43 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_pa2(struct s_s *a);
static int	ft_sort_pa3_inferior(struct s_s *a);
static int	ft_sort_pa3_superior(struct s_s *a);

static int	ft_sort_pa3_superior(struct s_s *a)
{
	if (a->stack[0] > a->stack[2])
	{
		if (a->stack[1] > a->stack[2])
		{
			if (ra (a) == -1)
				return (-1);
			if (sa (a) == -1)
				return (-1);
			return (0);
		}
		else if (a->stack[1] < a->stack[2])
		{
			if (ra (a) == -1)
				return (-1);
			return (0);
		}
	}
	else if (a->stack[1] < a->stack[2])
		if (sa(a) == -1)
			return (-1);
	return (0);
}

static int	ft_sort_pa3_inferior(struct s_s *a)
{
	if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2])
	{
		if (a->stack[0] > a->stack[2])
		{
			if (rra (a) == -1)
				return (-1);
			return (0);
		}
		if (a->stack[0] < a->stack[2])
			if (sa (a) == -1)
				return (-1);
		return (0);
	}
	return (0);
}

static int	ft_sort_pa2(struct s_s *a)
{
	if (a->stack[0] > a->stack[1])
		if (sa(a) == -1)
			return (-1);
	return (0);
}

int	alg_inferior(struct s_s *a)
{
	if (a->size == 1)
		return (0);
	if (a->size == 2)
		if (ft_sort_pa2(a) == -1)
			return (-1);
	if (a->size == 3)
	{
		if (a->stack[0] < a->stack[1])
			if (ft_sort_pa3_inferior(a) == -1)
				return (-1);
		if (a->stack[0] > a->stack[1])
			if (ft_sort_pa3_superior(a) == -1)
				return (-1);
	}
	return (0);
}
