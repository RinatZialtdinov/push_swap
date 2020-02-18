/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:05:52 by damerica          #+#    #+#             */
/*   Updated: 2020/02/16 16:05:53 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reserve_array(t_push **a, t_push **b)
{
	int i;

	i = 0;
	while ((*a)->len != i)
	{
		(*b)->array[i] = (*a)->array[(*a)->len - i - 1];
		i++;
	}
	i = 0;
	while ((*a)->len != i)
	{
		(*a)->array[i] = (*b)->array[i];
		(*b)->array[i] = 0;
		i++;
	}
}

int		check_array(t_push *a, t_push *b)
{
	int i;

	i = -1;
	if (b->len > 0)
		return (0);
	while (++i < a->len - 1)
		if (a->array[i] < a->array[i + 1])
			return (0);
	return (1);
}
