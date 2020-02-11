/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_less_100_cont.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:58:24 by damerica          #+#    #+#             */
/*   Updated: 2020/02/11 18:58:26 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void solution_less_100_e(t_push *a, t_push *b, t_len_ten ind)
{
	int i;
	int ind_min;
	i = 0;
	ind_min = find_min(a);
	ind.start = ind_min + 1;
	if (check_array(a, b))
		return ;
	if (ind.turn == 2 || ind.turn == 3)
	{
		//printf("a->len - %i\n", a->len);
		//printf("ind-stra -- %i\n", ind.start);
		return;
	}
	if (ind.turn == 1)
	{
		ind.turn++;
		ind.max = a->array[0];
		//printf_massiv(a, b);
		// printf("________________________________________________________________\n");
		//printf("ind-stra -- %i\n", ind.start);
		solution_less_100(a, b, ind);
	}
	//printf("ind.end in last - %i\n", ind.end);
	// printf("!!!!!!!!! %i !!!!!!!!\n", ind.end);
	// printf_massiv(a, b);
	// if (ind.turn == 1)
	// {
	// 	printf("kykyky\n");
	//ind.end = a->array[ind_min];
	// }
	while (a->array[i] != ind.end)
	{
		// printf("0v0v0v0v0\n");
		i++;
	}
	//printf("main_I - %i\n", i);
	while (a->len - 1 != i)
	{
		//printf("oleleoele\n");
		push(&a, &b, 'a');
	}
	ind.end = a->array[ind_min];
	// printf("__________oleoleoeloel______\n");
	// printf_massiv(a, b);

	if (ind.turn == 0 || ind.turn == 2)
	{
		// printf("ind.turn ================== %i\n", ind.turn);
		ind.turn++;
		solution_less_100_c(a, b, ind);
	}
	// ind.end = a->array[ind_min];
	if (ind.turn == 3)
	{
		// printf("ind.turn ================== %i\n", ind.turn);
		ind_min = find_min(a);
		ind_min = a->array[ind_min];
		while (ind_min != a->array[a->len - 1])
		{
			push(&a, &b, 'a');
		}
		solution_less_100_c(a, b, ind);
	}
	// while (ind.turn != 1)
	// {
	// 	ind.turn++;
	// 	solution_less_100_c(a, b, ind);
	// 	solution_less_100(a, b, ind);
	// }
	// printf("ind.start - %i\n", ind.start);
	// solution_less_100_c(a, b, ind);
	// ind_min = find_min(a);
	// ind.start = ind_min;
	// if (ind.turn == 1)
	// {
	// 	ind.turn = 2;
	// 	solution_less_100(a, b, ind);
	// }
}

void solution_less_100_d(t_push *a, t_push *b, t_len_ten ind)
{
	int i;

	i = 0;
	//printf("hey\n");
	while (a->array[i] != ind.item)
	{
		i++;
	}
	while (i != ind.len_b)
	{
		rotate(&a, 'a');
		i++;
	}

	// printf("___________100_d___________\n");
	// printf_massiv(a, b);
	solution_less_100_e(a, b, ind);
}

void solution_less_100_c(t_push *a, t_push *b, t_len_ten ind)
{
	int ind_min;
	int ind_max;

	ind.item = a->array[0];
	ind.len_b = b->len;
	//printf("ind.end in c %i\n", ind.end);
	// printf("___________100_c___________\n");
	// printf_massiv(a, b);
	if (b->len > 0)
	{
		while (b->len != 0)
		{
			ind_max = find_max(b);
			ind_min = find_min(b);
			decision_10(&a, &b, ind_max, ind_min);
		}
		solution_less_100_d(a, b, ind);
	}
	else
	{
		// printf("_!!!_!_!_!_!_!!_!_!_!_!\n");
		solution_less_100_e(a, b, ind);
	}
	
}
