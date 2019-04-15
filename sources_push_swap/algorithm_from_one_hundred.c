/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_from_one_hundred.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:02:06 by vkremen           #+#    #+#             */
/*   Updated: 2019/02/11 13:02:07 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm_from_one_hundred_2_1(int size, int *count, t_push_list *list)
{
	int		step;

	step = -1;
	while (++step < size)
	{
		if (list->stack_b[list->len_stack_b - 1] > list->median
			&& list->stack_b[list->len_stack_b - 1] > list->stack_b[0])
		{
			ft_printf("rrb\n");
			reverse_rotate(&list->stack_b, list->len_stack_b);
		}
		if (list->stack_b[0] >= list->median || size < 4)
		{
			push(&list->stack_a, &list->stack_b,
				&list->len_stack_a, &list->len_stack_b);
			ft_printf("pa\n");
			(*count)++;
		}
		else if (search_large_num(list) == 1)
		{
			ft_printf("rb\n");
			rotate(&list->stack_b, list->len_stack_b);
			list->count_back++;
		}
	}
}

void	algorithm_from_one_hundred_2(t_push_list *list, int size)
{
	int		step;
	int		count;

	if (second_ckeck_algorithm(list, size) == 0)
		return ;
	count = 0;
	list->count_back = 0;
	list->median = 0;
	find_median(list->stack_b, size, &list->median);
	algorithm_from_one_hundred_2_1(size, &count, list);
	step = -1;
	if (list->len_stack_b > 3 && list->len_stack_b > size)
		while (++step < list->count_back)
		{
			ft_printf("rrb\n");
			reverse_rotate(&list->stack_b, list->len_stack_b);
		}
	algorithm_from_one_hundred_1(list, count);
	if (size - count != 0)
		algorithm_from_one_hundred_2(list, size - count);
}

void	algorithm_from_one_hundred_1_1(int size, int *count, t_push_list *list)
{
	int		step;

	step = -1;
	while (++step < size - (*count))
	{
		if (list->stack_a[list->len_stack_a - 1] < list->median)
		{
			ft_printf("rra\n");
			reverse_rotate(&list->stack_a, list->len_stack_a);
		}
		if (list->stack_a[0] < list->median)
		{
			push(&list->stack_b, &list->stack_a,
				&list->len_stack_b, &list->len_stack_a);
			ft_printf("pb\n");
			(*count)++;
			step--;
		}
		else if (another_searh_smaller_num(list, size - (*count)) == 1)
		{
			ft_printf("ra\n");
			rotate(&list->stack_a, list->len_stack_a);
			list->count_back++;
		}
	}
}

void	algorithm_from_one_hundred_1(t_push_list *list, int size)
{
	int		count;
	int		step;

	if (firts_ckeck_algorithm(list, size) == 0)
		return ;
	count = 0;
	list->median = 0;
	list->count_back = 0;
	find_median(list->stack_a, size, &list->median);
	if (check_mass(*list) == 1)
		algorithm_from_one_hundred_1_1(size, &count, list);
	step = -1;
	if (list->block != 0)
		while (++step < list->count_back)
		{
			ft_printf("rra\n");
			reverse_rotate(&list->stack_a, list->len_stack_a);
		}
	if (check_mass(*list) == 1)
		algorithm_from_one_hundred_1(list, size - count);
	list->block++;
	if (size - count != 0)
		algorithm_from_one_hundred_2(list, count);
}
