/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_less_100_cont.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:58:24 by damerica          #+#    #+#             */
/*   Updated: 2020/02/11 18:58:26 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution_less_100_e_cont(t_push *a, t_push *b, t_len_ten ind, int ind_m)
{
	if (ind.turn == 0 || ind.turn == 2)
	{
		ind.turn++;
		solution_less_100_c(a, b, ind);
	}
	if (ind.turn == 3)
	{
		ind_m = find_min(a);
		ind_m = a->array[ind_m];
		while (ind_m != a->array[a->len - 1])
		{
			push(&a, &b, 'a');
		}
		solution_less_100_c(a, b, ind);
	}
}

void	solution_less_100_e(t_push *a, t_push *b, t_len_ten ind)
{
	int i;
	int ind_min;

	i = 0;
	ind_min = find_min(a);
	ind.start = ind_min + 1;
	if (check_array(a, b))
		return ;
	if (ind.turn == 2 || ind.turn == 3)
		return ;
	if (ind.turn == 1)
	{
		ind.turn++;
		ind.max = a->array[0];
		solution_less_100(a, b, ind);
	}
	while (a->array[i] != ind.end)
		i++;
	while (a->len - 1 != i)
		push(&a, &b, 'a');
	ind.end = a->array[ind_min];
	solution_less_100_e_cont(a, b, ind, ind_min);
}

void	solution_less_100_d(t_push *a, t_push *b, t_len_ten ind)
{
	int i;

	i = 0;
	while (a->array[i] != ind.item)
	{
		i++;
	}
	while (i != ind.len_b)
	{
		rotate(&a, 'a');
		i++;
	}
	solution_less_100_e(a, b, ind);
}

void	solution_less_100_c(t_push *a, t_push *b, t_len_ten ind)
{
	int ind_min;
	int ind_max;

	ind.item = a->array[0];
	ind.len_b = b->len;
	if (b->len > 0)
	{
		while (b->len != 0)
		{
			ind_max = find_max(b);
			ind_min = find_min(b);
			decision_10(&a, &b, ind_max, ind_min);
		}
		solution_less_100_d(a, b, ind);
	}
	else
	{
		solution_less_100_e(a, b, ind);
	}
}
