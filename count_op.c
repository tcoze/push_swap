/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 06:31:02 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/23 06:31:02 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_op(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	int	nb_op;

	ft_fill_infos(iall);
	iall->ipa.r_count = i;
	iall->ipa.rr_count = ft_val_abs(i - a->size);
	if (iall->ipa.r_count == 0)
		iall->ipa.rr_count = 0;
	if (a->stack[i] > b->stack[0])
	{
		nb_op = ft_c_o_s(i, a, b, iall);
		return (nb_op);
	}
	else
	{
		nb_op = ft_c_o_i(i, a, b, iall);
		return (nb_op);
	}
}
