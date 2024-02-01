/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:59:03 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/10 21:59:03 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(struct s_s *a)
{
	int	last_value;
	int	i;

	if (a->size > 1)
	{
		i = a->size;
		last_value = a->stack[i - 1];
		while (--i > 0)
			a->stack[i] = a->stack[i - 1];
		a->stack[i] = last_value;
		if (write (1, "rra\n", 4) == -1)
			return (-1);
	}
	return (0);
}

int	rrb(struct s_s *b)
{
	int	last_value;
	int	i;

	if (b->size > 1)
	{
		i = b->size;
		last_value = b->stack[i - 1];
		while (--i > 0)
			b->stack[i] = b->stack[i - 1];
		b->stack[i] = last_value;
		if (write (1, "rrb\n", 4) == -1)
			return (-1);
	}
	return (0);
}

int	rrr(struct s_s *a, struct s_s *b)
{
	int	last_value_a;
	int	last_value_b;
	int	i;
	int	j;

	if (a->size > 1 && b->size > 1)
	{
		i = b->size;
		j = a->size;
		last_value_b = b->stack[i - 1];
		last_value_a = a->stack[j - 1];
		while (--i > 0)
			b->stack[i] = b->stack[i - 1];
		while (--j > 0)
			a->stack[j] = a->stack[j - 1];
		b->stack[i] = last_value_b;
		a->stack[j] = last_value_a;
		if (write (1, "rrr\n", 4) == -1)
			return (-1);
	}
	return (0);
}
