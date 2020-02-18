/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:02:17 by damerica          #+#    #+#             */
/*   Updated: 2020/02/08 15:02:18 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_push
{
	int	len;
	int	*array;
}				t_push;

typedef struct	s_len_ten
{
	int	ind;
	int	item;
	int	len_a;
	int	len_b;
	int	start;
	int	end;
	int	turn;
	int	max;
}				t_len_ten;

void			solution_other_c(t_push *a, t_push *b, t_len_ten ind);
void			check_more_med(t_push *b, int *med);
int				check_num(t_push *b, int num);
int				find_med_10(t_push *a);
void			solution_less_10(t_push *a, t_push *b);
void			free_all(t_push *a, t_push *b);
void			free_struct_and_error(t_push *a, t_push *b);
void			reserve_array(t_push **a, t_push **b);
int				validation_b(t_push *a);
int				validation_a(int argc, char **argv);
int				ft_strcmp(const char *str1, const char *str2);
void			reverse_rotate_checker(t_push **el);
void			rotate_checker(t_push **el);
void			swap_checker(t_push **el);
void			push_checker(t_push **from, t_push **to);
void			solution_other(t_push *a, t_push *b, t_len_ten ind);
int				check_array(t_push *a, t_push *b);
int				find_max(t_push *b);
int				find_min(t_push *b);
int				find_med_100_b(t_push *a);
int				find_med_100(t_push *a, t_len_ten ind);
void			decision_10(t_push **a, t_push **b, int ind_max, int ind_min);
void			printf_massiv(t_push *a, t_push *b);
void			solution_less_100_e(t_push *a, t_push *b, t_len_ten ind);
void			solution_less_100_d(t_push *a, t_push *b, t_len_ten ind);
void			solution_less_100_c(t_push *a, t_push *b, t_len_ten ind);
void			solution_less_100_b(t_push *a, t_push *b, t_len_ten ind);
void			solution_less_100(t_push *a, t_push *b, t_len_ten ind);
void			solution_less_100(t_push *a, t_push *b, t_len_ten ind);
void			solution_less_100_c(t_push *a, t_push *b, t_len_ten ind);
void			push(t_push **from, t_push **to, char str);
void			swap(t_push **el, char str);
void			rotate(t_push **el, char str);
void			reverse_rotate(t_push **el, char str);
int				izmenenie_str(t_push **a, t_push **b, int argc, char **argv);
int				proverka_str(t_push **a, t_push **b, char **argv);
void			how_many_el(t_push **a, t_push **b, char **argv);
void			solution_less_3(t_push *el);
void			choose_case(int max, int mid, int min, t_push *el);
void			case_5();
void			case_4();
void			case_3();
void			case_2();
void			case_1();

#endif
