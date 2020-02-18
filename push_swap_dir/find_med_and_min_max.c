/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_med_and_min_max.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:02:18 by damerica          #+#    #+#             */
/*   Updated: 2020/02/17 18:02:19 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_med_100_b(t_push *a)
{
	int more;
	int i;
	int num;
	int j;

	j = 0;
	num = a->array[j];
	while (1)
	{
		i = 0;
		more = 0;
		while (i != a->len - 1)
		{
			if (num > a->array[i])
				more++;
			else if (num < a->array[i])
				more--;
			i++;
		}
		if (more == 0 || more == 1 || more == -1)
			break ;
		else
			num = a->array[++j];
	}
	return (num);
}

int		find_med_100(t_push *a, t_len_ten ind)
{
	int more;
	int i;
	int num;
	int j;

	j = ind.start;
	num = a->array[j];
	while (1)
	{
		i = ind.start;
		more = 0;
		while (i != a->len - 1)
		{
			if (num > a->array[i])
				more++;
			else if (num < a->array[i])
				more--;
			i++;
		}
		if (more == 0 || more == 1 || more == -1)
			break ;
		else
			num = a->array[++j];
	}
	return (num);
}

int		find_min(t_push *b)
{
	int min;
	int i;

	if (b->len == 0)
	{
		return (-1);
	}
	i = 1;
	min = b->array[0];
	while (b->len != i)
	{
		if (min > b->array[i])
			min = b->array[i];
		i++;
	}
	i = 0;
	while (b->array[i] != min)
	{
		i++;
	}
	return (i);
}

int		find_max(t_push *b)
{
	int max;
	int i;

	i = 1;
	max = b->array[0];
	while (b->len != i)
	{
		if (max < b->array[i])
			max = b->array[i];
		i++;
	}
	i = 0;
	while (b->array[i] != max)
	{
		i++;
	}
	return (i);
}
