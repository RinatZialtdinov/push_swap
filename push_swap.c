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

void printf_massiv(t_push *a, t_push *b)
{
	int	m = 0;
	printf("a massiv\n");
		while (a->len != m)
		{
			printf("%i, ", a->array[m]);
			m++;
		}
		printf("\n");
		// printf("el - %i\n", b->len);
		m = 0;
		printf("b massiv\n");
		while (b->len != m)
		{
			printf("%i, ", b->array[m]);
			m++;
		}
		printf("\n");
}

int find_med_10(t_push *a)
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

int find_min(t_push *b)
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

int find_max(t_push *b)
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

void decision_10(t_push **a, t_push **b, int ind_max, int ind_min)
{
	if (ind_max < (int) (*b)->len / 2)
	{
		if (ind_min < (int) (*b)->len / 2)
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
		else
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
	}
	else
	{
		if (ind_min < (int) (*b)->len / 2)
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
		else
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
	}
}

void solution_less_10_end(t_push **a)
{
	int first;
	int i;

	i = 1;
	first = (*a)->array[0];
	while (i != 3)
	{
		if (first < (*a)->array[i])
			first = (*a)->array[i];
		i++;
	}
	//printf("first - %i\n", first);
	while (first < (*a)->array[(*a)->len - 1])
	{
		rotate(a, 'a');
	}
}

void solution_less_10_b(t_push **a, t_push **b)
{
	int ind_min;
	int ind_max;

	solution_less_3(*a);
	while ((*b)->len != 0)
	{
		ind_min = find_min(*b);
		ind_max = find_max(*b);
		//printf("ind_min - %i, ind_max - %i\n", ind_min, ind_max);
		decision_10(a, b, ind_max, ind_min);
	}
	solution_less_10_end(a);
}

void solution_less_10(t_push *a, t_push *b)
{
	int med;
	int i;

	i = a->len - 1;
	med = find_med_10(a);
	//printf("%i\n", med);
	while (a->len != 3)
	{
		while (med < a->array[i])
		{
			if (i == a->len - 1)
			{
				//printf("1 - %i\n", i);
				push(&a, &b, 'a');
				break;
			}
			else
			{
				if (i >= (int) a->len / 2)
				{
					//printf("2 - %i\n", i);
					rotate(&a, 'a');
					if (i == a->len - 1)
						i = -1;
					i++;
				}
				else
				{
					//printf("3 - %i\n", i);
					reverse_rotate(&a, 'a');
					if (i == 0)
						i = a->len;
					i--;
				}
			}
		}
		i--;
	}
	solution_less_10_b(&a, &b);
}

int find_med_100_b(t_push *a)
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
		{
			break ;
		}
		else
		{
			num = a->array[++j];
		}
	}
	return(num);
}

int find_med_100(t_push *a, t_len_ten ind)
{
	int more;
	int i;
	int num;
	int j;
	// printf("ind.st - %i\n", ind.start);
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
		{
			break ;
		}
		else
		{
			num = a->array[++j];
		}
	}
	return(num);
}

int check_array(t_push *a, t_push *b)
{
	int k;
	int i;

	i = 0;
	k = a->array[i];
	if (b->len == 0)
	{
		while (i != a->len - 2)
		{
			if (k > a->array[i + 1])
			{
				k = a->array[i + 1];
				i++;
			}
			else
			{
				break ;
			}
		}
		if (i == a->len - 2)
			return (1);
	}
	return (0);
}

void solution(t_push *a, t_push *b)
{
	t_len_ten ind;
	
	ind.start = 0;
	ind.turn = 0;
	b->len = 0;
	ind.max = -2147483647;
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
	int *array;
	t_push *a;
	t_push *b;


	a = (t_push *)malloc(sizeof(t_push));
	b = (t_push *)malloc(sizeof(t_push));
	if (argc > 1)
	{
		izmenenie_str(&a, &b, argc, argv);
	}
	reserve_array(&a, &b);
	solution(a, b);
	printf_massiv(a, b);
	return (0);
}
