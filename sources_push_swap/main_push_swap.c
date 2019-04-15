/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:50:01 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/18 17:50:02 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_push_list	list;

	fill_stack_a_part_1(&list, argc, argv);
	if (check_same_num(list) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (check_mass(list) == 0)
		return (0);
	if (!(list.stack_b = (int*)malloc(sizeof(int) * list.len_stack_a)))
		return (0);
	list.len_stack_b = 0;
	list.block = 0;
	if (list.len_stack_a <= 6)
		algorithm_until_six_1(&list, list.len_stack_a);
	else if (list.len_stack_a > 6 && list.len_stack_a < 101)
		algorithm_from_six_until_one_hundred_1(&list, list.len_stack_a);
	else if (list.len_stack_a > 100)
		algorithm_from_one_hundred_1(&list, list.len_stack_a);
	return (0);
}
