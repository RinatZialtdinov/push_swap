/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proverka_str_in_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:01:28 by damerica          #+#    #+#             */
/*   Updated: 2020/02/18 17:01:29 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	how_many_el(t_push **a, t_push **b, char **argv)
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

int		proverka_str_a(int *minus, int *i, char **argv, long *num)
{
	*num = 0;
	*minus = 1;
	if (argv[1][*i] == '-' && argv[1][*i] != '\0')
	{
		*minus = -1;
		(*i)++;
	}
	while (argv[1][*i] >= '0' && argv[1][*i] <= '9' && argv[1][*i] != '\0')
	{
		*num = *num * 10 + argv[1][*i] - 48;
		(*i)++;
	}
	while (argv[1][*i] == ' ')
		(*i)++;
	if (*minus == 1)
	{
		if (*num > 2147483647)
			return (-1);
	}
	else
	{
		if ((*num) * (*minus) < -2147483648)
			return (-1);
	}
	return (0);
}

int		proverka_str(t_push **a, t_push **b, char **argv)
{
	int		i;
	long	num;
	int		j;
	int		minus;

	j = 0;
	i = 0;
	while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '-')
		i++;
	if (argv[1][i] == ' ' || argv[1][i] == '-')
	{
		i = 0;
		how_many_el(a, b, argv);
		while (argv[1][i] != '\0')
		{
			if (proverka_str_a(&minus, &i, argv, &num) == -1)
				return (-1);
			(*a)->array[j] = num * minus;
			j++;
		}
		(*a)->len = j;
		return (1);
	}
	return (0);
}
