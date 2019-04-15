/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:53:12 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/20 17:53:13 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_median(int *stack, int size, int *median)
{
	int		*cp_stack;
	int		step;

	if (!(cp_stack = (int*)malloc(sizeof(int) * size)))
		return ;
	step = -1;
	while (++step < size)
		cp_stack[step] = stack[step];
	step = -1;
	while (++step < size - 1)
		if (cp_stack[step] > cp_stack[step + 1])
		{
			check_swap(&cp_stack[step], &cp_stack[step + 1]);
			step = -1;
		}
	(*median) = cp_stack[(int)(size / 2)];
	free(cp_stack);
}

int		search_smaller_num(t_push_list *list, int num)
{
	int		step;
	int		size;

	step = -1;
	size = (num % 2 == 1 ? (int)(num / 2) + 1 : num / 2);
	while (++step < size)
		if (list->stack_a[step] < list->median)
			return (1);
	return (0);
}

int		another_searh_smaller_num(t_push_list *list, int size)
{
	int		step;

	step = -1;
	while (++step < size)
		if (list->stack_a[step] < list->median)
			return (1);
	return (0);
}

int		search_large_num(t_push_list *list)
{
	int		step;

	step = -1;
	while (++step < list->len_stack_b)
		if (list->stack_b[step] > list->median)
			return (1);
	return (0);
}

int		middle_of_three_num(t_push_list *list)
{
	int		max;
	int		min;
	int		step;

	max = list->stack_b[0];
	min = list->stack_b[0];
	step = -1;
	while (++step < 3)
	{
		if (list->stack_b[step] > max)
			max = list->stack_b[step];
		if (list->stack_b[step] < min)
			min = list->stack_b[step];
	}
	return (list->stack_b[0] + list->stack_b[1]
		+ list->stack_b[2] - max - min);
}
