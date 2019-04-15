/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_for_three_num.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:01:48 by vkremen           #+#    #+#             */
/*   Updated: 2019/02/11 13:01:49 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm_for_three_num_1_1(t_push_list *list)
{
	if (list->stack_a[0] > list->stack_a[1]
		&& list->stack_a[0] > list->stack_a[2])
	{
		check_rr(list);
		check_ss(list);
	}
	if (list->stack_a[1] > list->stack_a[0]
		&& list->stack_a[1] > list->stack_a[2])
	{
		check_rrr(list);
		check_ss(list);
	}
	if (list->stack_a[0] > list->stack_a[1]
		&& list->stack_a[0] < list->stack_a[2])
		check_ss(list);
}

void	algorithm_for_three_num_1_2(t_push_list *list)
{
	check_ss(list);
	if (list->stack_a[1] > list->stack_a[2])
	{
		ft_printf("ra\n");
		rotate(&list->stack_a, list->len_stack_a);
		check_ss(list);
		ft_printf("rra\n");
		reverse_rotate(&list->stack_a, list->len_stack_a);
		check_ss(list);
	}
}

int		algorithm_for_three_num_2_1(t_push_list *list)
{
	list->median = middle_of_three_num(list);
	if (list->stack_b[2] > list->median)
	{
		check_ss(list);
		ft_printf("rrb\n");
		reverse_rotate(&list->stack_b, list->len_stack_b);
	}
	if (list->stack_b[1] > list->median
		&& list->stack_b[2] == list->median)
	{
		ft_printf("rb\n");
		rotate(&list->stack_b, list->len_stack_b);
	}
	if (list->stack_b[1] > list->median
		&& list->stack_b[2] < list->median)
		check_ss(list);
	if (algorithm_for_three_num_2_1_2(list) == 0)
		return (0);
	else
		return (1);
}

int		algorithm_for_three_num_2_1_2(t_push_list *list)
{
	if (list->stack_b[0] > list->median)
	{
		push(&list->stack_a, &list->stack_b,
			&list->len_stack_a, &list->len_stack_b);
		ft_printf("pa\n");
		check_ss(list);
		push(&list->stack_a, &list->stack_b,
			&list->len_stack_a, &list->len_stack_b);
		ft_printf("pa\n");
		push(&list->stack_a, &list->stack_b,
			&list->len_stack_a, &list->len_stack_b);
		ft_printf("pa\n");
		return (0);
	}
	return (1);
}

void	algorithm_for_three_num_2_2(t_push_list *list)
{
	list->median = 0;
	find_median(list->stack_a, 3, &list->median);
	if (list->stack_b[0] < list->median)
	{
		check_ss(list);
		if (list->stack_b[0] < list->stack_b[2])
		{
			ft_printf("rb\n");
			rotate(&list->stack_b, list->len_stack_b);
			check_ss(list);
			ft_printf("rrb\n");
			reverse_rotate(&list->stack_b, list->len_stack_b);
		}
		check_ss(list);
	}
	if (list->stack_b[1] < list->stack_b[2])
	{
		ft_printf("rb\n");
		rotate(&list->stack_b, list->len_stack_b);
		check_ss(list);
		ft_printf("rrb\n");
		reverse_rotate(&list->stack_b, list->len_stack_b);
		check_ss(list);
	}
}
