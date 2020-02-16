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

void how_many_el(t_push **a, t_push **b, char **argv)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '-')
			i++;
		while (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			i++;
		}
		len++;
		while (argv[1][i] == ' ')
			i++;
	}
	(*a)->array = (int *)malloc(sizeof(int) * len);
	(*b)->array = (int *)malloc(sizeof(int) * len);
}

int proverka_str(t_push **a, t_push **b, char **argv)
{
	int i;
	long num;
	int j;
	int minus;

	j = 0;
	i = 0;
	while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '-')
	{
		i++;
	}
	// printf("i = %i\n", i);
	if (argv[1][i] == ' ' || argv[1][i] == '-')
	{
		i = 0;
		how_many_el(a, b, argv);
		while (argv[1][i] != '\0')
		{
			num = 0;
			minus = 1;
			// printf("i = %i\n", i);
			if (argv[1][i] == '-' && argv[1][i] != '\0')
			{
				minus = -1;
				i++;
			}
			while (argv[1][i] >= '0' && argv[1][i] <= '9' && argv[1][i] != '\0')
			{
				num = num * 10 + argv[1][i] - 48;
				i++;
			}
			while (argv[1][i] == ' ')
				i++;
			if (minus == 1)
			{
				if (num > 2147483647)
					return (-1);
			}
			else
			{
				if (num * minus < -2147483648)
					return (-1);
			}
			(*a)->array[j] = num * minus;
			j++;
		}
		(*a)->len = j;
		return (1);
	}
	return (0);
}

int izmenenie_str(t_push **a, t_push **b, int argc, char **argv)
{
	long num;
	int mod;
	int i;
	int j;
	int minus;
	
	i = 0;
	if (argc == 2)
	{
		num = proverka_str(a, b, argv);
		if (num == 1)
			return (0);
		if (num == -1)
			return (-1);
	}
	(*a)->array = (int *)malloc(sizeof(int) * (argc - 1));
	(*b)->array = (int *)malloc(sizeof(int) * (argc - 1));
	(*a)->len = argc - 1;
	while (argc > i + 1)
	{
		j = 0;
		num = 0;
		while (argv[i + 1][j] != '\0')
		{
			// printf("%s\n", argv[i+1]);
			minus = 1;
			if (argv[i + 1][j] == '-')
			{
				minus = -1;
				j++;
			}
			while (argv[i + 1][j] >= '0' && argv[i + 1][j] <= '9' && argv[i + 1][j] != '\0')
			{
				num = num * 10 + argv[i + 1][j] - 48;
				j++;
			}
			// num = num * 10 + argv[i + 1][j] - 48;
			// j++;
			//printf("num - %i\n", num);
		}
		if (minus == 1)
		{
			if (num > 2147483647)
				return (-1);
		}
		else
		{
			if (num * minus < -2147483648)
				return (-1);
		}
		(*a)->array[i] = num * minus;
		i++;
	}
	return (1);
}


int validation_a(int argc, char **argv)
{
	int i;
	int j;

	j = 1;
	while (j != argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if ((argv[j][i] < '0' || argv[j][i] > '9') && (argv[j][i] != '-' && argv[j][i] != ' '))
			{
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int validation_b(t_push *a)
{
	int i;
	int k;
	int m;

	i = 0;
	while (i != a->len)
	{
		k = a->array[i];
		m = i;
		while (i + 1 != a->len)
		{
			if (k == a->array[i + 1])
			{
				return (0);
			}
			i++;
		}
		i = m;
		i++;
	}
	return (1);
}
