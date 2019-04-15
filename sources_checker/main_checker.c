/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:43:03 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/30 12:43:04 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_instructions(t_push_list *list)
{
	int		step;

	step = -1;
	while (list->instructions[++step] != NULL)
		sort_tab_part_1(list, list->instructions[step]);
}

void	infinity_2(char **res, t_push_list *list)
{
	if ((*res)[0] != '\0')
	{
		list->instructions = ft_strsplit((*res), ' ');
		use_instructions(list);
	}
	free((*res));
}

void	infinity(t_push_list *list)
{
	char	*line;
	char	*res;

	res = (char*)malloc(sizeof(char));
	ft_bzero(res, sizeof(char));
	while (1)
	{
		line = NULL;
		get_next_line(0, &line);
		if (line != NULL && line[0] != '\0')
		{
			if (ft_strchr(line, ' '))
			{
				ft_printf("Error\n");
				exit(1);
			}
			res = ft_strjoin(res, line);
			res = ft_strjoin(res, " ");
			free(line);
		}
		else
			break ;
	}
	(line != NULL ? free(line) : 0);
	infinity_2(&res, list);
}

int		main(int argc, char **argv)
{
	t_push_list	list;
	char		c;

	if (argc < 2)
		return (0);
	fill_stack_a_part_1(&list, argc, argv);
	if (check_same_num(list) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (check_mass(list) == 0)
	{
		read(1, &c, 1);
		ft_printf("OK\n");
		return (0);
	}
	if (!(list.stack_b = (int*)malloc(sizeof(int) * list.len_stack_a)))
		return (0);
	list.len_stack_b = 0;
	infinity(&list);
	(check_mass(list) == 0 ? ft_printf("OK\n") : ft_printf("KO\n"));
	return (0);
}
