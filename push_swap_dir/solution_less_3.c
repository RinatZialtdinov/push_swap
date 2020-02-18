/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_less_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:46:48 by damerica          #+#    #+#             */
/*   Updated: 2020/02/08 16:46:49 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_case(int max, int mid, int min, t_push *a)
{
	if (max == a->array[0] && min == a->array[1])
	{
		case_1();
	}
	else if (min == a->array[0] && mid == a->array[1])
	{
		case_2();
	}
	else if (mid == a->array[0] && min == a->array[1])
	{
		case_3();
	}
	else if (mid == a->array[0] && max == a->array[1])
	{
		case_4();
	}
	else if (min == a->array[0] && max == a->array[1])
	{
		case_5();
	}
}

void	solution_less_3(t_push *a)
{
	int max;
	int min;
	int middle;

	if (a->array[2] > a->array[0] && a->array[2] > a->array[1])
		max = a->array[2];
	else if (a->array[0] > a->array[1])
		max = a->array[0];
	else
		max = a->array[1];
	if (a->array[2] < a->array[0] && a->array[2] < a->array[1])
		min = a->array[2];
	else if (a->array[0] > a->array[1])
		min = a->array[1];
	else
		min = a->array[0];
	middle = a->array[0] + a->array[1] + a->array[2] - min - max;
	choose_case(max, middle, min, a);
}
