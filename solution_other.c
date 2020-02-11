/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:06:40 by damerica          #+#    #+#             */
/*   Updated: 2020/02/11 19:06:41 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void solution_other(t_push *a, t_push *b, t_len_ten ind)
{
    int med;
    int i;
    int s;
    med = find_med_100(a, ind);
    printf("med - %i\n", med);
    i = a->len - 1;
    while (1)
    {
        if (a->array[i] < med && ind.max < a->array[i])
        {
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
    }
    // printf_massiv(a, b);
}