/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:47:00 by damerica          #+#    #+#             */
/*   Updated: 2020/02/13 18:47:02 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_push
{
	int	len;
	int	*array;
}				t_push;

int				proverka_str(t_push **a, t_push **b, char **argv);
void			free_all(t_push *a, t_push *b);
void			free_struct_and_error(t_push *a, t_push *b);
int				izmenenie_str(t_push **a, t_push **b, int argc, char **argv);
int				check_array(t_push *a, t_push *b);
void			reserve_array(t_push **a, t_push **b);
int				validation_b(t_push *a);
int				validation_a(int argc, char **argv);
int				ft_strcmp(const char *str1, const char *str2);
void			reverse_rotate_checker(t_push **el);
void			rotate_checker(t_push **el);
void			swap_checker(t_push **el);
void			push_checker(t_push **from, t_push **to);

#endif
