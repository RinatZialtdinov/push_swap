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

void solution_other_c(t_push *a, t_push *b, t_len_ten ind)
{
	int ind_min;
	int ind_max;


	ind.len_b = b->len;
	if (b->len > 0)
	{
		while (b->len != 0)
		{
			ind_max = find_max(b);
			ind_min = find_min(b);
			decision_10(&a, &b, ind_max, ind_min);
		}
		while (a->array[0] == a->array[a->len - 1] - 1)
		{
			rotate(&a, 'a');
		}
		ind_min = find_min(a);
		// printf("__________solution_other_CCCCCC_111________\n");
		// 	printf_massiv(a, b);
		if (ind_min == a->len - 1)
			return ;
		else
		{
			// printf("__________solution_other_CCCCCC_________\n");
			// printf_massiv(a, b);
			ind.max = a->array[0];
			ind.turn++;
			ind.start = ind_min;
			solution_other(a, b, ind);
		}
		if (check_array(a, b) == 1)
			return ;
	}
	return ;
}

void check_more_med(t_push *b, int *med)
{
	int i;

	i = 0;
	while (b->array[i] < *med && i != b->len - 1)
	{
		i++;
	}
	if (i == b->len - 1)
	{
		*med = find_med_100_b(b);
	}
} 

int check_num(t_push *b, int num)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i != b->len - 1)
	{
		if (num > b->array[i])
		{
			count++;
		}
		i++;
	}
	if (b->len / 2 + 5 > 45)
	{
		if (count > b->len / 2 + 5)
		{
			return (0);
		}
	}
	else
	{
		if (count >= 38)
		{
			return (0);
		}
	}
	
	return (1);
}

int find_min_num(int *b, int len)
{
	int min;
	int i;

	if (len == 0)
	{
		return (-1);
	}
	i = 1;
	min = b[0];
	while (len != i)
	{
		if (min > b[i])
			min = b[i];
		i++;
	}
	i = 0;
	while (b[i] != min && i != len)
	{
		i++;
	}
	return (i);
}

int check_min_num(t_push *b)
{
	int i;
	int num;
	int *copy;

	copy = (int *)malloc(sizeof(int) * (b->len));
	i = 0;
	while (i != b->len)
	{
		copy[i] = b->array[i];
		i++;
	}
	num = find_min(b);
	num = b->array[num];
	i = 0;
	while (i != 44)
	{
		copy[num] = 5000000 + num;
		num = find_min_num(copy, b->len);
		i++;
	}
	num = copy[num];
	// free(copy);
	return (num);
}

void solution_other_b_a(t_push *a, t_push *b, t_len_ten ind)
{
	int i;
	int max;
	int min;
	int copy;

	copy = a->array[0];
	min = find_min(b);
	min = b->array[min];
	max = find_max(b);
	max =b->array[max];
	i = a->len - 1;
	while (i != 0)
	{
		// printf_massiv(a, b);
		if (a->array[i] > min && a->array[i] < max)
		{
			while (i != a->len - 1)
			{
				rotate(&a, 'a');
				i++;
			}
			push(&a, &b, 'a');
			i = a->len;
		}
		i--;
	}
	// printf("_______b________a_\n");
	// printf_massiv(a, b);
	while (copy != a->array[0])
	{
		reverse_rotate(&a, 'a');
	}
	// printf("_______b____11111____a_\n");
	// printf_massiv(a, b);
	solution_other_c(a, b, ind);
}

void solution_other_b(t_push *a, t_push *b, t_len_ten ind)
{
	int med;
	int i;
	int min;
	// int num;

	med = find_med_100_b(b);
	while (1)
	{
		// printf("____www______solution_other_BBBBB_________\n");
		// printf_massiv(a, b);
		check_more_med(b, &med);
		//med = find_med_100_b(b);
		//num = check_min_num(b);
		// printf("num - %i\n", num);
		// printf_massiv(a, b);
		i = b->len - 1;
		min = find_min(b);
		while (med > b->array[i] && i != -1 && b->len != 0 && check_num(b, b->array[i]) == 1)  //b->array[i] < num)
		{
			i--;
		}
		if (b->len < 46)
		{
			break ;
		}
		else
		{
			decision_10(&a, &b, i, min);
		}
	}
	// printf("__________solution_other_BBBBB_________\n");
	// printf_massiv(a, b);
	solution_other_b_a(a, b, ind);
}

void solution_other(t_push *a, t_push *b, t_len_ten ind)
{
    int med;
    int i;
    int s;
	int ind_max;
	int ind_min;
    med = find_med_100(a, ind);
    // printf("med - %i\n", med);
	ind.len_a = a->len;
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
	while (ind.turn > 0 && a->array[0] != ind.max)
	{
		reverse_rotate(&a, 'a');
	}
	// printf("__________solution_other__________\n");
	// printf_massiv(a, b);
	if (b->len > 0)
		solution_other_b(a, b, ind);
	else
	{
		// printf("hey\n");
		i = find_min(a);
		while (i != a->len - 1 && check_array(a, b) != 1)
		{
			if (a->array[0] == a->array[a->len - 1] - 1)
				rotate(&a, 'a');
			else
			{
				i = find_min(a);
				if (i != a->len - 1)
					push(&a, &b, 'a');
			}
		}
		while (b->len != 0)
		{
			ind_max = find_max(b);
			ind_min = find_min(b);
			decision_10(&a, &b, ind_max, ind_min);
		}
		i = find_min(a);
		i = a->array[i];
		while (i != a->array[a->len - 1])
		{
			rotate(&a, 'a');
		}
		return ;
	}
}