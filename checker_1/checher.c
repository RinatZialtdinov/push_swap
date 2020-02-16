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

void		free_all(t_push *a, t_push *b)
{
	free(a->array);
	free(a);
	free(b->array);
	free(b);
}

void		act_case_2(t_push *a, t_push *b, char *buf)
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
		if (buf[0] != '\0' && buf[1] != '\0'
			&& buf[2] != '\0' && buf[3] != '\0')
			while (c != '\n')
				read(0, &c, 1);
		exit(0);
	}
}

void		act_case(t_push *a, t_push *b, char *buf)
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
		act_case_2(a, b, buf);
}

void		check_command(t_push *a, t_push *b)
{
	int		ans;
	char	ch;
	char	buf[4];
	int		i;

	ans = 0;
	ch = 0;
	i = 0;
	buf[3] = '\0';
	while ((ans = read(0, &ch, 1)))
	{
		buf[i++] = ch == '\n' ? '\0' : ch;
		if (ch == '\n' || i == 4)
		{
			act_case(a, b, buf);
			i = 0;
		}
	}
}

int main(int argc, char **argv)
{
    int *array;
	t_push *a;
	t_push *b;

	a = (t_push *)malloc(sizeof(t_push));
	b = (t_push *)malloc(sizeof(t_push));
	if ((validation_a(argc, argv)) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc > 1)
	{
		if (izmenenie_str(&a, &b, argc, argv) == -1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	reserve_array(&a, &b);
	if (validation_b(a) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
    check_command(a, b);
    if (check_array(a, b) == 1)
	    printf("OK\n");
	else
	{
		printf("KO\n");
	}
    return (0);
}
