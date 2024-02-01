/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_superior_part_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:16:07 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/18 01:02:10 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)s2[i]);
}

int	ft_val_abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

int	ft_abs(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	ft_fill_infos(struct s_i_a *iall)
{
	iall->ipa.s_count = 0;
	iall->ipa.ss_count = 0;
	iall->ipa.p_count = 0;
	iall->ipa.r_count = 0;
	iall->ipa.rab_count = 0;
	iall->ipa.rr_count = 0;
	iall->ipa.rrab_count = 0;
	iall->ipb.s_count = 0;
	iall->ipb.ss_count = 0;
	iall->ipb.p_count = 0;
	iall->ipb.r_count = 0;
	iall->ipb.rab_count = 0;
	iall->ipb.rr_count = 0;
	iall->ipb.rrab_count = 0;
}

int	ft_sort(int r_i, struct s_s *a, struct s_s *b, struct s_i_a *iall)
{
	ft_count_op(r_i, a, b, iall);
	while (iall->ipa.rrab_count-- > 0)
		if (rrr (a, b) == -1)
			return (-1);
	while (iall->ipa.rab_count-- > 0)
		if (rr (a, b) == -1)
			return (-1);
	while (iall->ipa.r_count-- > 0)
		if (ra (a) == -1)
			return (-1);
	while (iall->ipb.r_count-- > 0)
		if (rb (b) == -1)
			return (-1);
	while (iall->ipa.rr_count-- > 0)
		if (rra (a) == -1)
			return (-1);
	while (iall->ipb.rr_count-- > 0)
		if (rrb (b) == -1)
			return (-1);
	if (pb(a, b) == -1)
		return (-1);
	return (0);
}
