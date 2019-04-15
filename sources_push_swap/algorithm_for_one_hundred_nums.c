/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_for_one_hundred_nums.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:01:31 by vkremen           #+#    #+#             */
/*   Updated: 2019/02/11 13:01:32 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm_from_six_until_one_hundred_1_2(int size, int count,
	t_push_list *list)
{
	if (search_smaller_num(list, size - count) == 1)
	{
		ft_printf("ra\n");
		rotate(&list->stack_a, list->len_stack_a);
		list->count_back++;
	}
	else if (search_smaller_num(list, size - count) == 0)
	{
		ft_printf("rra\n");
		reverse_rotate(&list->stack_a, list->len_stack_a);
	}
}

void	algorithm_from_six_until_one_hundred_1_1(int size, int *count,
	t_push_list *list)
{
	int		step;

	step = -1;
	while (++step < size)
	{
		if (search_smaller_num(list, size - (*count)) == 0)
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
			if ((*count) == size / 2)
				break ;
		}
		else if (search_smaller_num(list, size - (*count)) == 1)
			algorithm_from_six_until_one_hundred_1_2(size, (*count), list);
	}
}

void	algorithm_from_six_until_one_hundred_2_1_3(t_push_list *list)
{
	if (list->stack_b[1] > list->median
		&& list->stack_b[1] > list->stack_a[0])
	{
		ft_printf("rr\n");
		rotate(&list->stack_a, list->len_stack_a);
		rotate(&list->stack_b, list->len_stack_b);
		list->count_back++;
		list->count_back_a++;
	}
	else
	{
		ft_printf("rb\n");
		rotate(&list->stack_b, list->len_stack_b);
		list->count_back++;
	}
}

void	algorithm_from_six_until_one_hundred_2_1_2(t_push_list *list, int num)
{
	int		step;

	if (list->count_back_a > 0 && num < list->stack_a[0])
	{
		while (list->stack_a[list->len_stack_a - 1] > num
			&& list->count_back_a != 0)
		{
			ft_printf("rra\n");
			reverse_rotate(&list->stack_a, list->len_stack_a);
			list->count_back_a--;
		}
	}
	step = 0;
	while (num > list->stack_a[step])
		step++;
	while (step > 0)
	{
		ft_printf("ra\n");
		rotate(&list->stack_a, list->len_stack_a);
		list->count_back_a++;
		step--;
	}
}

void	algorithm_from_six_until_one_hundred_2_1(int size, int *count,
	t_push_list *list)
{
	int		step;

	step = -1;
	while (++step < size)
	{
		if (list->stack_b[0] >= list->median || size < 4)
		{
			algorithm_from_six_until_one_hundred_2_1_2(list, list->stack_b[0]);
			push(&list->stack_a, &list->stack_b,
				&list->len_stack_a, &list->len_stack_b);
			ft_printf("pa\n");
			(*count)++;
		}
		else
			algorithm_from_six_until_one_hundred_2_1_3(list);
	}
}
