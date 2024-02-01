/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op_inff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:15:20 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/27 05:15:20 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_c_o_i_rr(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	int	k;

	k = b->size - 1;
	while (a->stack[i] < b->stack[k] && k > 1)
	{
		iall->ipb.rr_count++;
		k--;
	}
	while (a->stack[i] > b->stack[k] && k > 1)
	{
		iall->ipb.rr_count++;
		k--;
	}
	return (iall->ipb.rr_count);
}

static int	ft_c_o_i_r(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	int	j;

	j = 0;
	while (a->stack[i] < b->stack[j] && b->stack[j] > b->stack [j + 1]
		&& j < b->size - 2)
	{
		iall->ipb.r_count++;
		j++;
	}
	while (a->stack[i] < b->stack[j] && b->stack[j] < b->stack [j + 1]
		&& j < b->size - 2)
	{
		iall->ipb.r_count++;
		j++;
	}
	if (iall->ipb.r_count == 1 && b->size == 2)
		iall->ipb.r_count--;
	return (iall->ipb.r_count);
}

int	ft_c_o_i(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	int	r_v;

	r_v = 0;
	iall->ipb.r_count = ft_c_o_i_r(i, a, b, iall);
	iall->ipb.rr_count = ft_c_o_i_rr(i, a, b, iall);
	if (iall->ipb.r_count || iall->ipb.rr_count)
		r_v = ft_define_r_or_rr (iall);
	return (r_v);
}
