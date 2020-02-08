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

int find_med(t_push *a)
{
	int min;
	int min2;
	int min3;
	int i;
	
	i = 0;
	min = a->array[0];
	while (i != a->len)
	{
		if (a->array[i] < min)
			min = a->array[i];
		i++;
	}
	i = 0;
	if (min == a->array[0])
		min2 = a->array[1];
	else
		min2 = a->array[0];
	while (i != a->len)
	{
		if (a->array[i] < min2 && a->array[i] != min)
			min2 = a->array[i];
		i++;
	}
	i = 0;
	if (min == a->array[0] || min2 == a->array[0])
	{
		if (min == a->array[1] || min2 == a->array[1])
			min3 = a->array[2];
		else
			min3 = a->array[1];
	}
	else
		min3 = a->array[0];
	while (i != a->len)
	{
		if (a->array[i] < min3 && a->array[i] != min && a->array[i] != min2)
			min3 = a->array[i];
		i++;
	}
	return (min3);
}

void solution_less_10(t_push *a, t_push *b)
{
	int med;
	int i;
	int j;

	j = 0;
	i = a->len - 1;
	med = find_med(a);
	//printf("%i\n", med);
	while (a->len != 3)
	{
		while (med < a->array[i])
		{
			if (i == a->len - 1)
			{
				printf("1 - %i\n", i);
				push(&a, &b);
				break;
			}
			else
			{
				printf("2 - %i\n", i);
				rotate(&a);
				i++;
			}
			printf("hey\n");
		}
		i--;
	}
}

void solution(t_push *a, t_push *b)
{
	b->len = 0;
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
		;
	}
	else
	{
		;
	}
	
}

void reserve_array(t_push **a, t_push **b)
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

int main(int argc, char **argv)
{
	 int i;
	int *array;
	t_push *a;
	t_push *b;


	a = (t_push *)malloc(sizeof(t_push));
	b = (t_push *)malloc(sizeof(t_push));
	 i = 0;
	if (argc > 1)
	{
		izmenenie_str(&a, &b, argc, argv);
	}
	reserve_array(&a, &b);
	solution(a, b);
	while (a->len != i)
	{
		printf("%i\n", a->array[i]);
		i++;
	}
	printf("el - %i\n", a->len);
	return (0);
}
