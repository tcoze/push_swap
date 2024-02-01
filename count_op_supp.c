/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op_supp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3034/01/33 06:48:10 by tcoze             #+#    #+#             */
/*   Updated: 3034/01/33 06:48:10 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_c_o_s_rr(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	int	k;

	k = b->size - 1;
	while (a->stack[i] > b->stack[k] && b->stack[k] < b->stack[k - 1]
		&& k > 1)
	{
		iall->ipb.rr_count++;
		k--;
	}
	while (a->stack[i] > b->stack[k] && b->stack[k] > b->stack[k - 1]
		&& k > 1)
	{
		iall->ipb.rr_count++;
		k--;
	}
	return (iall->ipb.rr_count);
}

static int	ft_c_o_s_r(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	int	j;

	j = 0;
	while (a->stack[i] > b->stack[j] && b->stack[j] > b->stack[j + 1]
		&& j < b->size - 2)
	{
		iall->ipb.r_count++;
		j++;
	}
	while (a->stack[i] > b->stack[j] && b->stack[j] < b->stack[j + 1]
		&& j < b->size - 2)
	{
		iall->ipb.r_count++;
		j++;
	}
	while (a->stack[i] < b->stack[j] && j < b->size - 2)
	{
		iall->ipb.r_count++;
		j++;
	}
	return (iall->ipb.r_count);
}

int	ft_c_o_s(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	int	j;
	int	k;
	int	r_v;

	j = 0;
	k = b->size - 1;
	r_v = 0;
	if (a->stack[i] > b->stack[j] && a->stack[i] > b->stack[k]
		&& b->size <= 3)
		return (i);
	iall->ipb.r_count = ft_c_o_s_r(i, a, b, iall);
	iall->ipb.rr_count = ft_c_o_s_rr(i, a, b, iall);
	if (iall->ipb.r_count || iall->ipb.rr_count)
		r_v = ft_define_r_or_rr (iall);
	return (r_v);
}
