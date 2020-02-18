/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:16:31 by damerica          #+#    #+#             */
/*   Updated: 2020/02/06 14:16:32 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	act_case_2(t_push *a, t_push *b, char *buf, int *res)
{
	char c;

	c = 1;
	if (ft_strcmp(buf, "rr") == 0)
	{
		rotate_checker(&a);
		rotate_checker(&b);
	}
	else if (ft_strcmp(buf, "rrr") == 0)
	{
		reverse_rotate_checker(&a);
		reverse_rotate_checker(&b);
	}
	else
	{
		free_all(a, b);
		write(2, "ERROR\n", 6);
		*res = -1;
		if (buf[0] != '\0' && buf[1] != '\0'
			&& buf[2] != '\0' && buf[3] != '\0')
			while (c != '\n')
				read(0, &c, 1);
		exit(0);
	}
}

void	act_case(t_push *a, t_push *b, char *buf, int *res)
{
	if (ft_strcmp(buf, "pa") == 0)
		push_checker(&b, &a);
	else if (ft_strcmp(buf, "pb") == 0)
		push_checker(&a, &b);
	else if (ft_strcmp(buf, "sa") == 0)
		swap_checker(&a);
	else if (ft_strcmp(buf, "sb") == 0)
		swap_checker(&b);
	else if (ft_strcmp(buf, "ra") == 0)
		rotate_checker(&a);
	else if (ft_strcmp(buf, "rb") == 0)
		rotate_checker(&b);
	else if (ft_strcmp(buf, "rra") == 0)
		reverse_rotate_checker(&a);
	else if (ft_strcmp(buf, "rrb") == 0)
		reverse_rotate_checker(&b);
	else if (ft_strcmp(buf, "ss") == 0)
	{
		swap_checker(&a);
		swap_checker(&b);
	}
	else
		act_case_2(a, b, buf, res);
}

int		check_command(t_push *a, t_push *b)
{
	int		ans;
	char	ch;
	char	buf[4];
	int		i;
	int		res;

	res = 1;
	ans = 0;
	ch = 0;
	i = 0;
	buf[3] = '\0';
	while ((ans = read(0, &ch, 1)))
	{
		buf[i++] = ch == '\n' ? '\0' : ch;
		if (ch == '\n' || i == 4)
		{
			act_case(a, b, buf, &res);
			i = 0;
		}
	}
	return (res);
}

void	check_array_and_print_res(t_push *a, t_push *b)
{
	if (check_array(a, b) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int		main(int argc, char **argv)
{
	t_push	*a;
	t_push	*b;

	a = (t_push *)malloc(sizeof(t_push));
	b = (t_push *)malloc(sizeof(t_push));
	if ((validation_a(argc, argv)) == 0)
	{
		free_struct_and_error(a, b);
		return (0);
	}
	if (argc > 1)
	{
		if (izmenenie_str(&a, &b, argc, argv) == -1 || validation_b(a) == 0)
		{
			write(1, "Error\n", 6);
			free_all(a, b);
			return (0);
		}
		reserve_array(&a, &b);
		if (check_command(a, b) == 1)
			check_array_and_print_res(a, b);
		free_all(a, b);
		return (0);
	}
	free(a);
	free(b);
	return (0);
}
