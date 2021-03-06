/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:09:25 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/23 14:09:28 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_same_num(t_push_list list)
{
	int		step;
	int		step_2;
	int		count;

	step = -1;
	while (++step < list.len_stack_a)
	{
		step_2 = -1;
		count = 0;
		while (++step_2 < list.len_stack_a)
			if (list.stack_a[step] == list.stack_a[step_2])
				count++;
		if (count > 1)
			return (0);
	}
	return (1);
}

void	check_swap(int *a, int *b)
{
	int		swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int		check_mass(t_push_list list)
{
	int		step;

	step = -1;
	while (++step < list.len_stack_a - 1)
		if (list.stack_a[step] > list.stack_a[step + 1])
			return (1);
	return (0);
}

int		firts_ckeck_algorithm(t_push_list *list, int size)
{
	if (size <= 1)
		return (0);
	if (size == 2)
	{
		check_ss(list);
		return (0);
	}
	if (size == 3)
	{
		if (list->len_stack_a == 3)
		{
			algorithm_for_three_num_1_1(list);
			return (0);
		}
		else
			algorithm_for_three_num_1_2(list);
	}
	return (1);
}

int		second_ckeck_algorithm(t_push_list *list, int size)
{
	if (size < 1)
		return (0);
	if (size == 1)
	{
		push(&list->stack_a, &list->stack_b,
			&list->len_stack_a, &list->len_stack_b);
		ft_printf("pa\n");
		return (0);
	}
	if (size == 2)
		check_ss(list);
	if (size == 3)
	{
		if (list->len_stack_b == 3)
		{
			if (algorithm_for_three_num_2_1(list) == 0)
				return (0);
		}
		else if (list->len_stack_b > 3
			&& size < list->len_stack_b)
			algorithm_for_three_num_2_2(list);
	}
	return (1);
}
