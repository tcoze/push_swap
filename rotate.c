/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:02:47 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/16 04:02:47 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(struct s_s *a)
{
	int	temp;
	int	i;

	i = -1;
	if (a->size > 1)
	{
		while (++i < a->size - 1)
		{
			temp = a->stack[i];
			a->stack[i] = a->stack[i + 1];
			a->stack[i + 1] = temp;
		}
		if (write (1, "ra\n", 3) == -1)
			return (-1);
	}
	return (0);
}

int	rb(struct s_s *b)
{
	int	temp;
	int	i;

	i = -1;
	if (b->size > 1)
	{
		while (++i < b->size - 1)
		{
			temp = b->stack[i];
			b->stack[i] = b->stack[i + 1];
			b->stack[i + 1] = temp;
		}
		if (write (1, "rb\n", 3) == -1)
			return (-1);
	}
	return (0);
}

int	rr(struct s_s *a, struct s_s *b)
{
	int	temp;
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (a->size > 1 && b->size > 1)
	{
		while (++i < a->size - 1)
		{
			temp = a->stack[i];
			a->stack[i] = a->stack[i + 1];
			a->stack[i + 1] = temp;
		}
		while (++j < b->size - 1)
		{
			temp = b->stack[j];
			b->stack[j] = b->stack[j + 1];
			b->stack[j + 1] = temp;
		}
		if (write (1, "rr\n", 3) == -1)
			return (-1);
	}
	return (0);
}
