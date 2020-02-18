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

void	push_checker(t_push **from, t_push **to)
{
	if ((*from)->len != 0)
	{
		(*to)->array[(*to)->len] = (*from)->array[(*from)->len - 1];
		(*from)->array[(*from)->len - 1] = 0;
		(*to)->len++;
		(*from)->len--;
	}
}

void	swap_checker(t_push **el)
{
	int k;

	if ((*el)->len >= 2)
	{
		k = (*el)->array[(*el)->len - 1];
		(*el)->array[(*el)->len - 1] = (*el)->array[(*el)->len - 2];
		(*el)->array[(*el)->len - 2] = k;
	}
}

void	rotate_checker(t_push **el)
{
	int k;
	int len;

	if ((*el)->len < 2)
		return ;
	len = (*el)->len;
	k = (*el)->array[(*el)->len - 1];
	while (len != 1)
	{
		(*el)->array[len - 1] = (*el)->array[len - 2];
		len--;
	}
	(*el)->array[0] = k;
}

void	reverse_rotate_checker(t_push **el)
{
	int k;
	int i;

	if ((*el)->len < 2)
		return ;
	i = 0;
	k = (*el)->array[0];
	while ((*el)->len != i + 1)
	{
		(*el)->array[i] = (*el)->array[i + 1];
		i++;
	}
	(*el)->array[(*el)->len - 1] = k;
}
