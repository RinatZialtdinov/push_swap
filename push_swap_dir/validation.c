/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:55:45 by damerica          #+#    #+#             */
/*   Updated: 2020/02/17 17:55:46 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_push *a, t_push *b)
{
	free(a->array);
	free(a);
	free(b->array);
	free(b);
}

void	free_struct_and_error(t_push *a, t_push *b)
{
	write(1, "Error\n", 6);
	free(a);
	free(b);
}

int		validation_a(int argc, char **argv)
{
	int i;
	int j;

	j = 1;
	while (j != argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if ((argv[j][i] < '0' || argv[j][i] > '9') && (argv[j][i] != '-' &&
			argv[j][i] != ' ' && argv[j][i] != '+'))
				return (0);
			if (argv[j][i] == '-' || argv[j][i] == '+')
			{
				if (argv[j][i + 1] < '0' || argv[j][i + 1] > '9')
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int		validation_b(t_push *a)
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
