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

void how_many_el(t_push **a, t_push **b, char **argv)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (argv[1][i] != '\0')
	{
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
	int num;
	int j;

	j = 0;
	i = 0;
	while (argv[1][i] != '\0' && argv[1][i] != ' ')
	{
		i++;
	}
	if (argv[1][i] == ' ')
	{
		i = 0;
		how_many_el(a, b, argv);
		while (argv[1][i] != '\0')
		{
			num = 0;
			while (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				num = num * 10 + argv[1][i] - 48;
				i++;
			}
			while (argv[1][i] == ' ')
				i++;
			(*a)->array[j] = num;
			j++;
		}
		(*a)->len = j;
		return (1);
	}
	return (0);
}

void izmenenie_str(t_push **a, t_push **b, int argc, char **argv)
{
	int num;
	int mod;
	int i;
	int j;

	i = 0;
	if (argc == 2)
	{
		num = proverka_str(a, b, argv);
		if (num == 1)
			return ;
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
			//printf("char = %c\n", argv[i + 1][j]);
			num = num * 10 + argv[i + 1][j] - 48;
			j++;
			//printf("num - %i\n", num);
		}
		(*a)->array[i] = num;
		i++;
	}
}
