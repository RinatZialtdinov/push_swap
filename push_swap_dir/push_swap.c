/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:16:17 by damerica          #+#    #+#             */
/*   Updated: 2020/02/06 14:16:19 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	solution(t_push *a, t_push *b)
{
	t_len_ten	ind;

	ind.start = 0;
	ind.turn = 0;
	b->len = 0;
	ind.max = -2147483647;
	if (check_array(a, b) == 0)
	{
		if (a->len <= 3)
		{
			solution_less_3(a);
		}
		else if (a->len <= 10)
		{
			solution_less_10(a, b);
		}
		else if (a->len <= 100)
		{
			solution_less_100(a, b, ind);
		}
		else
		{
			solution_other(a, b, ind);
		}
	}
}

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

int		main(int argc, char **argv)
{
	t_push	*a;
	t_push	*b;

	a = (t_push *)malloc(sizeof(t_push));
	b = (t_push *)malloc(sizeof(t_push));
	if ((validation_a(argc, argv)) == 0)
	{
		free_struct_and_error(a, b);
		return (0);
	}
	if (argc > 1)
	{
		if (izmenenie_str(&a, &b, argc, argv) == -1 || validation_b(a) == 0)
		{
			write(1, "Error\n", 6);
			free_all(a, b);
			return (0);
		}
		reserve_array(&a, &b);
		solution(a, b);
		free_all(a, b);
		return (0);
	}
	free(a);
	free(b);
	return (0);
}
