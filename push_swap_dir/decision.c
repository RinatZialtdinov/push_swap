/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:12:12 by damerica          #+#    #+#             */
/*   Updated: 2020/02/17 18:12:17 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fourth_if(t_push **b, t_push **a, int ind_max, int ind_min)
{
	if ((*b)->len - 1 - ind_min < (*b)->len - 1 - ind_max)
	{
		while (ind_min != (*b)->len - 1)
		{
			rotate(b, 'b');
			ind_min++;
		}
		push(b, a, 'b');
		rotate(a, 'a');
	}
	else
	{
		while (ind_max != (*b)->len - 1)
		{
			rotate(b, 'b');
			ind_max++;
		}
		push(b, a, 'b');
	}
}

void	third_if(t_push **b, t_push **a, int ind_max, int ind_min)
{
	if ((*b)->len - 1 - ind_max > ind_min)
	{
		while (ind_min != -1)
		{
			reverse_rotate(b, 'b');
			ind_min--;
		}
		push(b, a, 'b');
		rotate(a, 'a');
	}
	else
	{
		while (ind_max != (*b)->len - 1)
		{
			rotate(b, 'b');
			ind_max++;
		}
		push(b, a, 'b');
	}
}

void	second_if(t_push **b, t_push **a, int ind_max, int ind_min)
{
	if ((*b)->len - 1 - ind_min <= ind_max)
	{
		while (ind_min != (*b)->len - 1)
		{
			rotate(b, 'b');
			ind_min++;
		}
		push(b, a, 'b');
		rotate(a, 'a');
	}
	else
	{
		while (ind_max != -1)
		{
			reverse_rotate(b, 'b');
			ind_max--;
		}
		push(b, a, 'b');
	}
}

void	first_if(t_push **b, t_push **a, int ind_max, int ind_min)
{
	if (ind_min < ind_max)
	{
		while (ind_min != -1)
		{
			reverse_rotate(b, 'b');
			ind_min--;
		}
		push(b, a, 'b');
		rotate(a, 'a');
	}
	else
	{
		while (ind_max != -1)
		{
			reverse_rotate(b, 'b');
			ind_max--;
		}
		push(b, a, 'b');
	}
}

void	decision_10(t_push **a, t_push **b, int ind_max, int ind_min)
{
	if (ind_max < (int)(*b)->len / 2)
	{
		if (ind_min < (int)(*b)->len / 2)
		{
			first_if(b, a, ind_max, ind_min);
		}
		else
		{
			second_if(b, a, ind_max, ind_min);
		}
	}
	else
	{
		if (ind_min < (int)(*b)->len / 2)
		{
			third_if(b, a, ind_max, ind_min);
		}
		else
		{
			fourth_if(b, a, ind_max, ind_min);
		}
	}
}
