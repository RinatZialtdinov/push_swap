/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:02:17 by damerica          #+#    #+#             */
/*   Updated: 2020/02/08 15:02:18 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_push
{
    int len;
    int *array;
}              t_push;

void push(t_push **from, t_push **to);
void swap(t_push **el);
void rotate(t_push **el);
void reverse_rotate(t_push **el);
void izmenenie_str(t_push **a, t_push **b, int argc, char **argv);
int proverka_str(t_push **a, t_push **b, char **argv);
void how_many_el(t_push **a, t_push **b, char **argv);
void solution_less_3(t_push *el);
void choose_case(int max, int mid, int min, t_push *el);
void case_5();
void case_4();
void case_3();
void case_2();
void case_1();

