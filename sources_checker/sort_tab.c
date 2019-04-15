/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:22:55 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/30 15:22:58 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_tab_part_1(t_push_list *list, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		swap(&list->stack_a, list->len_stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		swap(&list->stack_b, list->len_stack_b);
	else if (ft_strcmp(str, "ss") == 0)
	{
		swap(&list->stack_a, list->len_stack_a);
		swap(&list->stack_b, list->len_stack_b);
	}
	else if (ft_strcmp(str, "pb") == 0)
		push(&list->stack_b, &list->stack_a,
			&list->len_stack_b, &list->len_stack_a);
	else if (ft_strcmp(str, "pa") == 0)
		push(&list->stack_a, &list->stack_b,
			&list->len_stack_a, &list->len_stack_b);
	else if (ft_strcmp(str, "ra") == 0)
		rotate(&list->stack_a, list->len_stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		rotate(&list->stack_b, list->len_stack_b);
	else
		sort_tab_part_2(list, str);
	ft_strdel(&str);
}

void	sort_tab_part_2(t_push_list *list, char *str)
{
	if (ft_strcmp(str, "rr") == 0)
	{
		rotate(&list->stack_a, list->len_stack_a);
		rotate(&list->stack_b, list->len_stack_b);
	}
	else if (ft_strcmp(str, "rra") == 0)
		reverse_rotate(&list->stack_a, list->len_stack_a);
	else if (ft_strcmp(str, "rrb") == 0)
		reverse_rotate(&list->stack_b, list->len_stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		reverse_rotate(&list->stack_a, list->len_stack_a);
		reverse_rotate(&list->stack_b, list->len_stack_b);
	}
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}
