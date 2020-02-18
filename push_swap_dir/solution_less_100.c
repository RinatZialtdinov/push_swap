/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_less_100.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:55:41 by damerica          #+#    #+#             */
/*   Updated: 2020/02/11 18:55:43 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution_less_100_b(t_push *a, t_push *b, t_len_ten ind)
{
	int med;
	int min;
	int i;
	int s;

	s = 0;
	med = find_med_100_b(b);
	while (1)
	{
		i = b->len - 1;
		min = find_min(b);
		while (med > b->array[i] && i != -1 && b->len != 0)
		{
			i--;
		}
		if (i == -1)
		{
			break ;
		}
		else
		{
			decision_10(&a, &b, i, min);
		}
	}
	solution_less_100_c(a, b, ind);
}

void	if_in_sol_less_100(t_push *a, t_push *b, int *i)
{
	if (*i == a->len - 1)
		push(&a, &b, 'a');
	else
	{
		if (*i < (int)a->len / 2)
		{
			while (*i != -1)
			{
				reverse_rotate(&a, 'a');
				(*i)--;
			}
			push(&a, &b, 'a');
		}
		else
		{
			while (*i != a->len - 1)
			{
				rotate(&a, 'a');
				(*i)++;
			}
			push(&a, &b, 'a');
		}
	}
	*i = a->len - 1;
}

void	solution_less_100_1(t_push *a, t_push *b, t_len_ten ind)
{
	ind.end = a->array[a->len - 1];
	while (ind.turn > 0 && a->array[0] != ind.max)
		reverse_rotate(&a, 'a');
	solution_less_100_b(a, b, ind);
}

void	solution_less_100(t_push *a, t_push *b, t_len_ten ind)
{
	int med;
	int i;
	int s;

	i = a->len - 1;
	med = find_med_100(a, ind);
	while (1)
	{
		if (a->array[i] < med && ind.max < a->array[i])
			if_in_sol_less_100(a, b, &i);
		else
		{
			s = 0;
			while ((s != a->len && a->array[s] >= med) ||
			(s != a->len && a->array[s] <= ind.max && ind.turn > 0))
			{
				s++;
			}
			if (s == a->len)
				break ;
			i--;
		}
	}
	solution_less_100_1(a, b, ind);
}
