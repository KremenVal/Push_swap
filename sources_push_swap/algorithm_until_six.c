/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_until_six.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:47:38 by vkremen           #+#    #+#             */
/*   Updated: 2019/02/04 15:47:42 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm_until_six_2(t_push_list *list, int size)
{
	int		step;

	if (second_ckeck_algorithm(list, size) == 0)
		return ;
	list->median = 0;
	(size > 2 ? find_median(list->stack_b, size, &list->median) : 0);
	step = -1;
	while (++step < size)
		if (list->stack_a[0] >= list->median || size < 4)
		{
			push(&list->stack_a, &list->stack_b,
				&list->len_stack_a, &list->len_stack_b);
			ft_printf("pa\n");
		}
}

void	algorithm_until_six_1_2(t_push_list *list)
{
	ft_printf("ra\n");
	rotate(&list->stack_a, list->len_stack_a);
	if (list->stack_a[0] >= list->median
		&& list->stack_a[1] >= list->median && list->block != 0)
	{
		check_rr(list);
		check_ss(list);
	}
	list->block++;
}

int		algorithm_until_six_1_1(t_push_list *list, int size, int *count)
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
			return (0);
	}
	else if (check_mass(*list) == 1
		&& search_smaller_num(list, size - (*count)) == 1)
		algorithm_until_six_1_2(list);
	return (1);
}

void	algorithm_until_six_1(t_push_list *list, int size)
{
	int		step;
	int		count;

	if (firts_ckeck_algorithm(list, size) == 0)
		return ;
	list->block = 0;
	list->median = 0;
	(size > 2 ? find_median(list->stack_a, size, &list->median) : 0);
	if (check_mass(*list) == 0)
		return ;
	step = -1;
	count = 0;
	while (++step < size)
		if (algorithm_until_six_1_1(list, size, &count) == 0)
			break ;
	if (check_mass(*list) == 1)
		algorithm_until_six_1(list, size - count);
	if (size - count != 0)
		algorithm_until_six_2(list, count);
}
