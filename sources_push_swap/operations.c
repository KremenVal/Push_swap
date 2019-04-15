/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:48:49 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/18 17:48:51 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		swap(int **tab, int len_tab)
{
	int		swap;

	if (len_tab <= 1)
		return (0);
	swap = (*tab)[0];
	(*tab)[0] = (*tab)[1];
	(*tab)[1] = swap;
	return (1);
}

void	rotate(int **tab, int len_tab)
{
	int		num;
	int		step;

	if (len_tab < 1)
		return ;
	step = -1;
	num = (*tab)[0];
	while (++step < len_tab - 1)
		(*tab)[step] = (*tab)[step + 1];
	(*tab)[step] = num;
}

void	reverse_rotate(int **tab, int len_tab)
{
	int		step;

	step = len_tab - 1;
	while (step > 0)
	{
		check_swap(&(*tab)[step], &(*tab)[step - 1]);
		step--;
	}
}

void	push(int **tab_a, int **tab_b, int *len_tab_a, int *len_tab_b)
{
	int		step;

	(*len_tab_b)--;
	step = -1;
	if ((*len_tab_a) == 0)
	{
		(*tab_a)[0] = (*tab_b)[0];
		(*len_tab_a)++;
		while (++step < (*len_tab_b))
			(*tab_b)[step] = (*tab_b)[step + 1];
		return ;
	}
	(*len_tab_a)++;
	step = (*len_tab_a) - 1;
	while (step > 0)
	{
		(*tab_a)[step] = (*tab_a)[step - 1];
		step--;
	}
	(*tab_a)[0] = (*tab_b)[0];
	step = -1;
	while (++step < (*len_tab_b))
		(*tab_b)[step] = (*tab_b)[step + 1];
}
