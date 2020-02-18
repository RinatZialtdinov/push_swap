/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:45:03 by damerica          #+#    #+#             */
/*   Updated: 2020/02/08 16:45:04 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	while_in_izm_str(char **argv, int *i, int *j, int *minus)
{
	long long num;

	num = 0;
	*minus = 1;
	if (argv[*i + 1][*j] == '-')
	{
		*minus = -1;
		(*j)++;
	}
	if (argv[*i + 1][*j] == '+')
		(*j)++;
	while (argv[*i + 1][*j] >= '0' && argv[*i + 1][*j] <= '9' &&
	argv[*i + 1][*j] != '\0')
	{
		num = num * 10 + argv[*i + 1][*j] - 48;
		(*j)++;
	}
	return (num);
}

int			izmenenie_str_end(t_push **a, int minus, long long num, int *i)
{
	int l;

	l = 0;
	if (minus == 1)
	{
		if (num > 2147483647)
			l = -1;
	}
	else
	{
		if (num * minus < -2147483648)
			l = -1;
	}
	(*a)->array[*i] = num * minus;
	(*i)++;
	return (l);
}

void		initial(t_push **a, t_push **b, int argc)
{
	(*a)->array = (int *)malloc(sizeof(int) * (argc - 1));
	(*b)->array = (int *)malloc(sizeof(int) * (argc - 1));
	(*a)->len = argc - 1;
}

int			izmenenie_str(t_push **a, t_push **b, int argc, char **argv)
{
	long long	num;
	int			i;
	int			j;
	int			minus;

	i = 0;
	if (argc == 2)
	{
		num = proverka_str(a, b, argv);
		if (num == 1)
			return (0);
		if (num == -1)
			return (-1);
	}
	initial(a, b, argc);
	while (argc > i + 1)
	{
		j = 0;
		while (argv[i + 1][j] != '\0')
			num = while_in_izm_str(argv, &i, &j, &minus);
		if (izmenenie_str_end(a, minus, num, &i) == -1)
			return (-1);
	}
	return (1);
}
