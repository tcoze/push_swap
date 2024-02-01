/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_superior_part_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:41:12 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/18 00:41:12 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_define_r_or_rr_special(struct s_i_a *iall)
{
	if (iall->ipa.r_count == 0 && iall->ipa.rr_count == 0)
	{
		if (iall->ipb.r_count == 0 && iall->ipb.rr_count == 0)
			return (0);
		if (iall->ipb.r_count <= iall->ipb.rr_count)
		{
			iall->ipb.rr_count = 0;
			return (iall->ipb.r_count);
		}
		else
		{
			iall->ipb.r_count = 0;
			return (iall->ipb.rr_count);
		}
	}
	return (-1);
}

static int	ft_choose_rr(struct s_i_a *iall)
{
	iall->ipa.r_count = 0;
	iall->ipb.r_count = 0;
	while (iall->ipa.rr_count && iall->ipb.rr_count)
	{
		iall->ipa.rr_count--;
		iall->ipb.rr_count--;
		iall->ipa.rrab_count++;
	}
	return (iall->ipa.rr_count + iall->ipb.rr_count + iall->ipa.rrab_count);
}

static int	ft_choose_r(struct s_i_a *iall)
{
	iall->ipa.rr_count = 0;
	iall->ipb.rr_count = 0;
	while (iall->ipa.r_count && iall->ipb.r_count)
	{
		iall->ipa.r_count--;
		iall->ipb.r_count--;
		iall->ipa.rab_count++;
	}
	return (iall->ipa.r_count + iall->ipb.r_count + iall->ipa.rab_count);
}

int	ft_define_r_or_rr(struct s_i_a *iall)
{
	int	r;
	int	rr;
	int	temp;

	r = ft_abs (iall->ipa.r_count, iall->ipb.r_count);
	rr = ft_abs (iall->ipa.rr_count, iall->ipb.rr_count);
	temp = ft_define_r_or_rr_special (iall);
	if (temp != -1)
		return (temp);
	if (r <= rr)
		return (ft_choose_r(iall));
	else
		return (ft_choose_rr(iall));
}
