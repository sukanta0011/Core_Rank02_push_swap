/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:02:32 by sudas             #+#    #+#             */
/*   Updated: 2025/09/23 19:02:32 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_dbl_ll	*lst_a;
	t_dbl_ll	*lst_b;
	t_dll_info	*lst_a_info;
	t_dll_info	*lst_b_info;
	int			*temp_array;
	// int			arr[] = {29, 5, -93};
	int			arr[] = {2, 1, 3, 6, 5, 8, -33, 0, 1, -50, 20};

	lst_a_info = NULL;
	lst_a_info = init_lst_info(lst_a_info);
	lst_b_info = NULL;
	lst_b_info = init_lst_info(lst_b_info);
	for (int i = 0; i < 11; i++)
		lst_a = add_at_back(lst_a_info, arr[i]);
	(void)lst_b;
	(void)lst_a;

	temp_array = create_temp_array(lst_a_info);
	// swap_array_elements(temp_array, 0, lst_a_info->size - 1);
	quick_sort(temp_array, 0, lst_a_info->size - 1);
	for (int i = 0; i < 11; i++)
		printf("%d, ", temp_array[i]);
	// sort_stack(lst_a_info, lst_b_info);

	// printf("%s\n", "-----------a-----------");
	// print_lst(lst_a_info);
	// printf("%s\n", "-----------b-----------");
	// print_lst(lst_b_info);

	// if (is_assending(lst_a_info))
	// 	printf("Sorted\n");
	// else
	// 	printf("Not-Sorted\n");

	free_lst(lst_a_info);
	free_lst(lst_b_info);
}
