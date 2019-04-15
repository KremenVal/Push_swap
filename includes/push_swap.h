/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:00:25 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/18 18:00:30 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct			s_struct_stack
{
	int					len_stack_a;
	int					len_stack_b;
	int					*stack_a;
	int					*stack_b;
	int					median;
	int					count_back;
	int					count_back_a;
	int					block;
	char				**instructions;
}						t_push_list;

void					fill_stack_a_part_1(t_push_list *list, int argc,
										char **argv);
int						count_digits(char **argv, int i);
void					fill_stack_a_part_2(t_push_list *list, char **argv,
										char **str, int i);
void					put_num_in_stack(t_push_list *list,
										long long int num);
int						check_mass(t_push_list list);
int						check_same_num(t_push_list list);
void					check_swap(int *a, int *b);
void					algorithm_until_six_1(t_push_list *list, int size);
int						firts_ckeck_algorithm(t_push_list *list, int size);
void					check_ss(t_push_list *list);
int						swap(int **tab, int len_tab);
void					algorithm_for_three_num_1_1(t_push_list *list);
void					find_median(int *stack, int size, int *median);
void					check_rr(t_push_list *list);
void					rotate(int **tab, int len_tab);
void					check_rrr(t_push_list *list);
void					reverse_rotate(int **tab, int len_tab);
void					algorithm_for_three_num_1_2(t_push_list *list);
int						algorithm_until_six_1_1(t_push_list *list, int size,
										int *count);
int						search_smaller_num(t_push_list *list, int num);
void					push(int **tab_a, int **tab_b,
										int *len_tab_a, int *len_tab_b);
void					algorithm_until_six_1_2(t_push_list *list);
void					algorithm_until_six_2(t_push_list *list, int size);
int						second_ckeck_algorithm(t_push_list *list, int size);
int						algorithm_for_three_num_2_1(t_push_list *list);
int						middle_of_three_num(t_push_list *list);
int						algorithm_for_three_num_2_1_2(t_push_list *list);
void					algorithm_for_three_num_2_2(t_push_list *list);
void					algorithm_from_six_until_one_hundred_1(t_push_list
										*list, int size);
void					algorithm_from_six_until_one_hundred_1_1(int size,
										int *count, t_push_list *list);
void					algorithm_from_six_until_one_hundred_1_2(int size,
										int count, t_push_list *list);
void					algorithm_from_six_until_one_hundred_2(t_push_list
										*list, int size);
void					algorithm_from_six_until_one_hundred_2_1(int size,
										int *count, t_push_list *list);
void					algorithm_from_six_until_one_hundred_2_1_2(t_push_list
										*list, int num);
void					algorithm_from_six_until_one_hundred_2_1_3(t_push_list
										*list);
void					algorithm_from_six_until_one_hundred_2_2(t_push_list
										*list, int size);
void					algorithm_from_one_hundred_1(t_push_list *list,
										int size);
void					algorithm_from_one_hundred_1_1(int size, int *count,
										t_push_list *list);
int						another_searh_smaller_num(t_push_list *list, int size);
void					algorithm_from_one_hundred_2(t_push_list *list,
										int size);
void					algorithm_from_one_hundred_2_1(int size, int *count,
										t_push_list *list);
int						search_large_num(t_push_list *list);
void					infinity(t_push_list *list);
void					use_instructions(t_push_list *list);
void					sort_tab_part_1(t_push_list *list, char *str);
void					sort_tab_part_2(t_push_list *list, char *str);

#endif
