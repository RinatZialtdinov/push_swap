/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_less_10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:07:24 by damerica          #+#    #+#             */
/*   Updated: 2020/02/17 18:07:25 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution_less_10_end(t_push **a)
{
	int first;
	int i;

	i = 1;
	first = (*a)->array[0];
	while (i != 3)
	{
		if (first < (*a)->array[i])
			first = (*a)->array[i];
		i++;
	}
	while (first < (*a)->array[(*a)->len - 1])
	{
		rotate(a, 'a');
	}
}

void	solution_less_10_b(t_push **a, t_push **b)
{
	int ind_min;
	int ind_max;

	solution_less_3(*a);
	while ((*b)->len != 0)
	{
		ind_min = find_min(*b);
		ind_max = find_max(*b);
		decision_10(a, b, ind_max, ind_min);
	}
	solution_less_10_end(a);
}

void	else_in_solution(int *i, t_push *a)
{
	if (*i >= (int)a->len / 2)
	{
		rotate(&a, 'a');
		if (*i == a->len - 1)
			*i = -1;
		(*i)++;
	}
	else
	{
		reverse_rotate(&a, 'a');
		if (*i == 0)
			*i = a->len;
		(*i)--;
	}
}

void	solution_less_10(t_push *a, t_push *b)
{
	int med;
	int i;

	i = a->len - 1;
	med = find_med_10(a);
	while (a->len != 3)
	{
		while (med < a->array[i])
		{
			if (i == a->len - 1)
			{
				push(&a, &b, 'a');
				break ;
			}
			else
			{
				else_in_solution(&i, a);
			}
		}
		i--;
	}
	solution_less_10_b(&a, &b);
}
