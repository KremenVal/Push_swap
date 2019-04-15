/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:07:40 by vkremen           #+#    #+#             */
/*   Updated: 2019/02/11 13:07:43 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_ss(t_push_list *list)
{
	if (list->stack_a[0] > list->stack_a[1]
		&& list->stack_b[0] < list->stack_b[1]
		&& list->len_stack_b > 1)
	{
		ft_printf("ss\n");
		swap(&list->stack_a, list->len_stack_a);
		swap(&list->stack_b, list->len_stack_b);
	}
	if (list->stack_a[0] > list->stack_a[1])
	{
		ft_printf("sa\n");
		swap(&list->stack_a, list->len_stack_a);
	}
	if (list->stack_b[0] < list->stack_b[1]
		&& list->len_stack_b > 1)
	{
		ft_printf("sb\n");
		swap(&list->stack_b, list->len_stack_b);
	}
}

void	check_rr(t_push_list *list)
{
	if ((list->stack_a[0] > list->stack_a[1] &&
		list->stack_a[0] > list->stack_a[2])
		&& (list->stack_b[0] < list->stack_b[1]
		&& list->stack_b[0] < list->stack_b[2]))
	{
		ft_printf("rr\n");
		rotate(&list->stack_a, list->len_stack_a);
		rotate(&list->stack_b, list->len_stack_b);
	}
	if (list->stack_a[0] > list->stack_a[1] &&
		list->stack_a[0] > list->stack_a[2])
	{
		ft_printf("ra\n");
		rotate(&list->stack_a, list->len_stack_a);
	}
	if (list->stack_b[0] < list->stack_b[1]
		&& list->stack_b[0] < list->stack_b[2])
	{
		ft_printf("rb\n");
		rotate(&list->stack_b, list->len_stack_b);
	}
}

void	check_rrr(t_push_list *list)
{
	if ((list->stack_a[2] < list->stack_a[0]
		&& list->stack_b[2] > list->stack_b[0]) ||
		(list->stack_a[2] > list->stack_a[0]
		&& list->stack_b[2] < list->stack_b[0])
		|| (list->stack_a[2] > list->stack_a[0]
		&& list->stack_b[2] > list->stack_b[0]))
	{
		ft_printf("rrr\n");
		reverse_rotate(&list->stack_a, list->len_stack_a);
		reverse_rotate(&list->stack_b, list->len_stack_b);
	}
	else
	{
		if (list->stack_a[2] > list->stack_a[0]
			|| list->stack_a[2] < list->stack_a[0])
		{
			ft_printf("rra\n");
			reverse_rotate(&list->stack_a, list->len_stack_a);
		}
		if (list->stack_b[2] > list->stack_b[0])
		{
			ft_printf("rrb\n");
			reverse_rotate(&list->stack_b, list->len_stack_b);
		}
	}
}
