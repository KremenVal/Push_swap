/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_from_six_until_one_hundred.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:02:23 by vkremen           #+#    #+#             */
/*   Updated: 2019/02/11 13:02:24 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm_from_six_until_one_hundred_2_2(t_push_list *list, int size)
{
	int		step;

	step = -1;
	if (list->len_stack_b > 3 && list->len_stack_b > size)
	{
		if (list->count_back_a > 0 && list->count_back > 0)
			while (list->count_back > 0 && list->count_back_a > 0)
			{
				ft_printf("rrr\n");
				reverse_rotate(&list->stack_a, list->len_stack_a);
				reverse_rotate(&list->stack_b, list->len_stack_b);
				list->count_back_a--;
				list->count_back--;
			}
		while (++step < list->count_back)
		{
			ft_printf("rrb\n");
			reverse_rotate(&list->stack_b, list->len_stack_b);
		}
	}
}

void	algorithm_from_six_until_one_hundred_2(t_push_list *list, int size)
{
	int		step;
	int		count;

	if (second_ckeck_algorithm(list, size) == 0)
		return ;
	count = 0;
	list->count_back = 0;
	list->count_back_a = 0;
	list->median = 0;
	find_median(list->stack_b, size, &list->median);
	algorithm_from_six_until_one_hundred_2_1(size, &count, list);
	algorithm_from_six_until_one_hundred_2_2(list, size);
	step = -1;
	while (++step < list->count_back_a)
	{
		ft_printf("rra\n");
		reverse_rotate(&list->stack_a, list->len_stack_a);
	}
	algorithm_from_six_until_one_hundred_1(list, count);
	if (size - count > 0)
		algorithm_from_six_until_one_hundred_2(list, size - count);
}

void	algorithm_from_six_until_one_hundred_1(t_push_list *list, int size)
{
	int		count;
	int		step;

	if (firts_ckeck_algorithm(list, size) == 0)
		return ;
	list->block = 0;
	count = 0;
	list->median = 0;
	list->count_back = 0;
	find_median(list->stack_a, size, &list->median);
	if (check_mass(*list) == 1)
		algorithm_from_six_until_one_hundred_1_1(size, &count, list);
	step = -1;
	if (list->block != 0)
		while (++step < list->count_back)
		{
			ft_printf("rra\n");
			reverse_rotate(&list->stack_a, list->len_stack_a);
		}
	if (check_mass(*list) == 1)
		algorithm_from_six_until_one_hundred_1(list, size - count);
	list->block++;
	if (size - count != 0)
		algorithm_from_six_until_one_hundred_2(list, count);
}
