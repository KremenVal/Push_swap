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

void	fill_stack_a_part_1(t_push_list *list, int argc, char **argv)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		str = argv[i];
		count += count_digits(argv, i);
	}
	if (!(list->stack_a = (int*)malloc(sizeof(int) * count)))
		return ;
	list->len_stack_a = count;
	i = 0;
	while (++i < argc)
	{
		str = argv[i];
		fill_stack_a_part_2(list, argv, &str, i);
	}
}

int		count_digits(char **argv, int i)
{
	int		count;
	int		index;

	count = 0;
	index = -1;
	while (argv[i][++index])
		if ((argv[i][index] >= '0' && argv[i][index] <= '9')
			&& (argv[i][index + 1] == ' ' || argv[i][index + 1] == '\0'))
			count++;
	return (count);
}

void	fill_stack_a_part_2(t_push_list *list, char **argv, char **str, int i)
{
	int				j;
	long long int	num;

	j = -1;
	while (argv[i][++j])
	{
		if ((argv[i][j] >= '0' && argv[i][j] <= '9')
			&& (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0'))
		{
			num = ft_atoi((*str));
			if (num > 2147483647 || num < -2147483648)
			{
				ft_printf("Error\n");
				exit(1);
			}
			put_num_in_stack(list, num);
			(*str) = (char*)argv[i] + j + 1;
		}
		else if ((argv[i][j] < '0' || argv[i][j] > '9')
			&& argv[i][j] != ' ' && argv[i][j] != '-' && argv[i][j] != '+')
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}

void	put_num_in_stack(t_push_list *list, long long int num)
{
	static int		index = 0;

	list->stack_a[index++] = num;
}
