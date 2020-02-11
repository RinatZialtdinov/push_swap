/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_less_100.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:55:41 by damerica          #+#    #+#             */
/*   Updated: 2020/02/11 18:55:43 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void solution_less_100_b(t_push *a, t_push *b, t_len_ten ind)
{
	int med;
	int min;
	int i;
	int s;
	int m = 0;
	s = 0;
	med = find_med_100_b(b);
	//printf("med - %i\n", med);
	while (1)
	{
		// printf("___________100_b___________\n");
		// printf_massiv(a, b);
		i = b->len - 1;
		min = find_min(b);
		while (med > b->array[i] && i != -1 && b->len != 0)
		{
			i--;
		}
		//printf("i - %i\n", i);
		if (i == -1)
		{
			break ;
		}
		else
		{
			decision_10(&a, &b, i, min);
		}
	}
//	printf("ind.end in b %i\n", ind.end);
	solution_less_100_c(a, b, ind);
}

void solution_less_100(t_push *a, t_push *b, t_len_ten ind)
{
	int med;
	int i;
	int s;

	s = 0;
	i = a->len - 1;
	med = find_med_100(a, ind);
	//printf("med - %i\n", med);
	//printf("ind.max - %i\n", ind.max);
	while (1)
	{
		if (a->array[i] < med && ind.max < a->array[i])
		{
			//printf("i - %i\n", i);
			if (i == a->len - 1)
			{
				push(&a, &b, 'a');
				i = a->len - 1;
			}
			else
			{
				if (i < (int) a->len / 2)
				{
					//printf("%i\n", i);
					while (i != -1)
					{
						reverse_rotate(&a, 'a');
						i--;
					}
					push(&a, &b, 'a');
					 i = a->len - 1;
				}
				else
				{
					while (i != a->len - 1)
					{
						rotate(&a, 'a');
						i++;
					}
					push(&a, &b, 'a');
					 i = a->len - 1;
				}
			}
		}
		else
		{
			 //printf("s - %i\nsum - %i\n", s, a->len);
			s = 0;
			while ((s != a->len && a->array[s] >= med) || (s != a->len && a->array[s] <= ind.max && ind.turn > 0))
			{
				s++;
			}
			//printf("s -  %i\n minus - %i\n", s, a->len - ind.start);
			if (s == a->len )
				break;
			i--;
		}
		//i--;
	
	
	// printf("_________100__________\n");
	// printf_massiv(a, b);
	}
	ind.end = a->array[a->len - 1];
	// printf("ind.end ==== %i\n", ind.end);
	while (ind.turn > 0 && a->array[0] != ind.max)
	{
		reverse_rotate(&a, 'a');
	}
	//printf("he212y\n");
//	ind.end = a->array[a->len - 1];
	//printf("ind.end -=- %i\n", ind.end);
	solution_less_100_b(a, b, ind);
}
