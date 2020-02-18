/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_med_10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:46:00 by damerica          #+#    #+#             */
/*   Updated: 2020/02/18 16:46:01 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_med_10_cont(int *min, int *min2, int *min3, t_push *a)
{
	int i;

	i = 0;
	if (*min == a->array[0] || *min2 == a->array[0])
	{
		if (*min == a->array[1] || *min2 == a->array[1])
			*min3 = a->array[2];
		else
			*min3 = a->array[1];
	}
	else
		*min3 = a->array[0];
	while (i != a->len)
	{
		if (a->array[i] < *min3 && a->array[i] != *min && a->array[i] != *min2)
			*min3 = a->array[i];
		i++;
	}
}

int		find_med_10(t_push *a)
{
	int	min;
	int	min2;
	int	min3;
	int	i;

	i = 0;
	min = a->array[0];
	while (i != a->len)
	{
		if (a->array[i] < min)
			min = a->array[i];
		i++;
	}
	i = 0;
	min2 = min == a->array[0] ? a->array[1] : a->array[0];
	while (i != a->len)
	{
		if (a->array[i] < min2 && a->array[i] != min)
			min2 = a->array[i];
		i++;
	}
	i = 0;
	find_med_10_cont(&min, &min2, &min3, a);
	return (min3);
}
