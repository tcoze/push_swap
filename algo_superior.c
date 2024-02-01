/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_superior_part_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:11:26 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/19 01:34:24 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_f_case(struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	int	op1;

	if (a->stack[0] < b->stack[0] && a->stack[0] > b->stack[1] && b->size == 2)
	{
		if (pb (a, b) == -1)
			return (-1);
		if (sb(b) == -1)
			return (-1);
		return (1);
	}
	op1 = 1 + ft_count_op(0, a, b, iall);
	if (op1 == 1)
	{
		if (pb(a, b) == -1)
			return (-1);
		return (op1);
	}
	return (op1);
}

int	alg_superior(struct s_s *a, struct s_s *b)
{
	int			r_i;
	int			i;
	int			op1;
	t_infos_all	iall;

	i = 0;
	r_i = 0;
	op1 = ft_check_f_case (a, b, &iall);
	if (op1 == -1)
		return (-1);
	if (op1 == 1)
		return (0);
	while (i++ < a->size - 1)
	{
		if (1 + ft_count_op(i, a, b, &iall) < op1)
		{
			op1 = 1 + ft_count_op(i, a, b, &iall);
			r_i = i;
		}
	}
	if (ft_sort(r_i, a, b, &iall) == -1)
		return (-1);
	return (0);
}
