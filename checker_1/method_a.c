/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:26:23 by damerica          #+#    #+#             */
/*   Updated: 2020/02/13 18:26:24 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void push_checker(t_push **from, t_push **to)
{
	if ((*from)->len != 0)
	{
		(*to)->array[(*to)->len] = (*from)->array[(*from)->len - 1];
		(*from)->array[(*from)->len - 1] = 0;
		(*to)->len++;
		(*from)->len--;
		// if (str == 'a')
		// {
		//     write(1, "pb\n", 3);
		// }
		// else
		// {
		//     write(1, "pa\n", 3);
		// }
	}
}

void swap_checker(t_push **el)
{
	int k;

	if ((*el)->len > 2)
	{
		k = (*el)->array[(*el)->len - 1];
		(*el)->array[(*el)->len - 1] = (*el)->array[(*el)->len - 2];
		(*el)->array[(*el)->len - 2] = k;
		// if (str == 'a')
		// {
		//     write(1, "sa\n", 3);
		// }
		// else
		// {
		//     write(1, "sb\n", 3);
		// } 
	}
}

void rotate_checker(t_push **el)
{
	int k;
	int len;

	len = (*el)->len;
	k = (*el)->array[(*el)->len - 1];
	while (len != 1)
	{
		(*el)->array[len - 1] = (*el)->array[len - 2];
		len--;
	}
	(*el)->array[0] = k;
	// if (str == 'a')
	// {
	//     write(1, "ra\n", 3);
	// }
	// else
	// {
	//     write(1, "rb\n", 3);
	// } 
}

void reverse_rotate_checker(t_push **el)
{
	int k;
	int i;

	i = 0;
	k = (*el)->array[0];
	//printf("el->len - %i\n", (*el)->len);
	while ((*el)->len != i + 1)
	{
		(*el)->array[i] = (*el)->array[i + 1];
		i++;
	}
	(*el)->array[(*el)->len - 1] = k;
	// if (str == 'a')
	// {
	//     write(1, "rra\n", 4);
	// }
	// else
	// {
	//     write(1, "rrb\n", 4);
	// } 
}
