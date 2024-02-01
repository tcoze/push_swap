/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:44:58 by tcoze             #+#    #+#             */
/*   Updated: 2024/01/18 00:49:52 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_s
{
	int	*stack;
	int	size;
}	t_stack;

typedef struct s_i
{
	int	s_count;
	int	ss_count;
	int	p_count;
	int	r_count;
	int	rab_count;
	int	rr_count;
	int	rrab_count;
}	t_infos;

typedef struct s_i_a
{
	t_infos	ipa;
	t_infos	ipb;
}	t_infos_all;

int		sa(struct s_s *a);
int		sb(struct s_s *b);
int		ss(struct s_s *a, struct s_s *b);
int		pa(struct s_s *a, struct s_s *b);
int		pb(struct s_s *a, struct s_s *b);
int		ra(struct s_s *a);
int		rb(struct s_s *b);
int		rr(struct s_s *a, struct s_s *b);
int		rra(struct s_s *a);
int		rrb(struct s_s *b);
int		rrr(struct s_s *a, struct s_s *b);
int		alg_inferior(struct s_s *a);
int		alg_superior(struct s_s *a, struct s_s *b);
int		ft_count_op(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall);
int		ft_sort(int r_i, struct s_s *a, struct s_s *b, struct s_i_a *iall);
int		alg_superior_a3i(struct s_s *a);
int		alg_superior_a3s(struct s_s *a);
int		ft_fill_back_a(struct s_s *a, struct s_s *b);
int		ft_abs(int a, int b);
int		ft_val_abs(int a);
int		ft_define_r_or_rr(struct s_i_a *iall);
void	ft_fill_infos(struct s_i_a *iall);
int		ft_check_entry(char *argv[], struct s_s a);
int		ft_c_o_s(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall);
int		ft_c_o_i(int i, struct s_s *a, struct s_s *b, struct s_i_a *iall);
int		ft_strcmp(const char *s1, const char *s2);

#endif
