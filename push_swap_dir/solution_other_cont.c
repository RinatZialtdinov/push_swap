/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_other_cont.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:17:30 by damerica          #+#    #+#             */
/*   Updated: 2020/02/17 18:17:32 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_ind(t_len_ten ind, t_push *a, int ind_min, t_push *b)
{
	ind.max = a->array[0];
	ind.turn++;
	ind.start = ind_min;
	solution_other(a, b, ind);
}

void	solution_other_c(t_push *a, t_push *b, t_len_ten ind)
{
	int	ind_min;
	int	ind_max;

	ind.len_b = b->len;
	if (b->len > 0)
	{
		while (b->len != 0)
		{
			ind_max = find_max(b);
			ind_min = find_min(b);
			decision_10(&a, &b, ind_max, ind_min);
		}
		while (a->array[0] == a->array[a->len - 1] - 1)
			rotate(&a, 'a');
		ind_min = find_min(a);
		if (ind_min == a->len - 1)
			return ;
		else
		{
			add_ind(ind, a, ind_min, b);
		}
		if (check_array(a, b) == 1)
			return ;
	}
	return ;
}

void	check_more_med(t_push *b, int *med)
{
	int i;

	i = 0;
	while (b->array[i] < *med && i != b->len - 1)
	{
		i++;
	}
	if (i == b->len - 1)
	{
		*med = find_med_100_b(b);
	}
}

int		check_num(t_push *b, int num)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i != b->len - 1)
	{
		if (num > b->array[i])
			count++;
		i++;
	}
	if (b->len / 2 + 5 > 45)
	{
		if (count > b->len / 2 + 5)
			return (0);
	}
	else
	{
		if (count >= 38)
			return (0);
	}
	return (1);
}
