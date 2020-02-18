/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:06:40 by damerica          #+#    #+#             */
/*   Updated: 2020/02/11 19:06:41 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution_other_b_a(t_push *a, t_push *b, t_len_ten ind)
{
	int i;
	int max;
	int min;
	int copy;

	copy = a->array[0];
	min = b->array[find_min(b)];
	max = b->array[find_max(b)];
	i = a->len;
	while (--i != 0)
	{
		if (a->array[i] > min && a->array[i] < max)
		{
			while (i != a->len - 1)
			{
				rotate(&a, 'a');
				i++;
			}
			push(&a, &b, 'a');
			i = a->len;
		}
	}
	while (copy != a->array[0])
		reverse_rotate(&a, 'a');
	solution_other_c(a, b, ind);
}

void	solution_other_b(t_push *a, t_push *b, t_len_ten ind)
{
	int med;
	int i;
	int min;

	med = find_med_100_b(b);
	while (1)
	{
		check_more_med(b, &med);
		i = b->len - 1;
		min = find_min(b);
		while (med > b->array[i] && i != -1 && b->len != 0 &&
		check_num(b, b->array[i]) == 1)
			i--;
		if (b->len < 46)
			break ;
		else
			decision_10(&a, &b, i, min);
	}
	solution_other_b_a(a, b, ind);
}

void	else_in_other(int i, t_push *a, t_push *b)
{
	int ind_max;
	int ind_min;

	i = find_min(a);
	while (i != a->len - 1 && check_array(a, b) != 1)
	{
		if (a->array[0] == a->array[a->len - 1] - 1)
			rotate(&a, 'a');
		else
		{
			i = find_min(a);
			if (i != a->len - 1)
				push(&a, &b, 'a');
		}
	}
	while (b->len != 0)
	{
		ind_max = find_max(b);
		ind_min = find_min(b);
		decision_10(&a, &b, ind_max, ind_min);
	}
	i = a->array[find_min(a)];
	while (i != a->array[a->len - 1])
		rotate(&a, 'a');
	return ;
}

void	first_if_other(int *i, t_push *a, t_push *b)
{
	if (*i == a->len - 1)
	{
		push(&a, &b, 'a');
	}
	else
	{
		if (*i < (int)a->len / 2)
		{
			while (*i != -1)
			{
				reverse_rotate(&a, 'a');
				(*i)--;
			}
		}
		else
		{
			while (*i != a->len - 1)
			{
				rotate(&a, 'a');
				(*i)++;
			}
		}
		push(&a, &b, 'a');
	}
	*i = a->len - 1;
}

void	solution_other(t_push *a, t_push *b, t_len_ten ind)
{
	int med;
	int i;
	int s;

	med = find_med_100(a, ind);
	ind.len_a = a->len;
	i = a->len - 1;
	while (1)
	{
		if (a->array[i] < med && ind.max < a->array[i])
			first_if_other(&i, a, b);
		else
		{
			s = 0;
			while ((s != a->len && a->array[s] >= med) ||
			(s != a->len && a->array[s] <= ind.max && ind.turn > 0))
				s++;
			if (s == a->len)
				break ;
			i--;
		}
	}
	while (ind.turn > 0 && a->array[0] != ind.max)
		reverse_rotate(&a, 'a');
	b->len > 0 ? solution_other_b(a, b, ind) : else_in_other(i, a, b);
}
