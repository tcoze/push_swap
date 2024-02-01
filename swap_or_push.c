/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_or_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:58:50 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/10 21:58:50 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(struct s_s *a)
{
	int	temp;

	if (a->size > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
		if (write (1, "sa\n", 3) == -1)
			return (-1);
	}
	return (0);
}

int	sb(struct s_s *b)
{
	int	temp;

	if (b->size > 1)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
		if (write (1, "sb\n", 3) == -1)
			return (-1);
	}
	return (0);
}

int	ss(struct s_s *a, struct s_s *b)
{
	int	temp;

	if (a->size > 1 && b->size > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
		if (write (1, "ss\n", 3) == -1)
			return (-1);
	}
	return (0);
}

int	pa(struct s_s *a, struct s_s *b)
{
	int	i;
	int	j;

	if (b->size > 0)
	{
		i = a->size;
		j = 0;
		while (i > 0)
		{
			a->stack[i] = a->stack[i - 1];
			i--;
		}
		a->stack[i] = b->stack[i];
		while (j < b->size - 1)
		{
			b->stack[j] = b->stack[j + 1];
			j++;
		}
		b->size--;
		a->size++;
		if (write (1, "pa\n", 3) == -1)
			return (-1);
	}
	return (0);
}

int	pb(struct s_s *a, struct s_s *b)
{
	int	i;
	int	j;

	if (a->size > 0)
	{
		i = b->size;
		j = 0;
		while (i > 0)
		{
			b->stack[i] = b->stack[i - 1];
			i--;
		}
		b->stack[i] = a->stack[i];
		while (j < a->size - 1)
		{
			a->stack[j] = a->stack[j + 1];
			j++;
		}
		a->size--;
		b->size++;
		if (write (1, "pb\n", 3) == -1)
			return (-1);
	}
	return (0);
}
