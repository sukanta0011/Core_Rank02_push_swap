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
	int			*sorted_arr;
	int			size = 200;
	// int			arr[] = {29, 5, -93};
	int			arr[] = {-81, 0, 47, 84, 55, -3, -33, 29, 5, -93, -47, 72, 34, -15, 43, 0, 98, -73, -9, -18, -44, 67, 86, -94, -77, -59, 82, -90, 60, -21, 61, 29, 80, -43, -38, -16, 54, 30, 63, -42, -13, -85, 80, -80, -50, -27, -29, -53, -50, 62, -20, 6, -21, -35, 13, 2, -44, -56, 12, 66, 23, -28, -5, 2, -20, 7, 36, -67, 87, -2, -58, -76, -37, -79, -56, 14, -56, -35, 11, -5, 78, 41, -100, -44, -95, -37, 8, -38, 7, -81, -73, -70, -59, -28, -18, 21, 30, -82, 5, 16, -34, -3, 40, 30, -32, 35, 94, 13, 50, -46, -93, -23, 96, 58, -17, 51, -79, 91, 63, 28, 60, 41, 8, -99, -88, 91, -28, -8, 59, 27, 59, 75, -77, -52, -46, -8, 33, -53, 55, -17, -48, 62, 10, -53, -31, 94, 98, -10, 84, 61, 69, 44, -49, -74, -5, -87, 67, 17, 6, 25, -56, -36, -50, -83, 12, 4, 9, 96, 52, -87, -22, 54, 25, 88, -100, 95, 31, 48, -16, 15, -42, -98, -92, 9, -71, -47, 23, 96, 70, -72, -29, -87, -58, 21, 82, 4, -76, -10, -1, 26};

	lst_a_info = NULL;
	lst_a_info = init_lst_info(lst_a_info);
	lst_b_info = NULL;
	lst_b_info = init_lst_info(lst_b_info);
	for (int i = 0; i < size; i++)
		lst_a = add_at_back(lst_a_info, arr[i]);
	(void)lst_b;
	(void)lst_a;

	sorted_arr = create_temp_array(lst_a_info);
	// swap_array_elements(temp_array, 0, lst_a_info->size - 1);
	quick_sort(sorted_arr, 0, size - 1);
	// for (int i = 0; i < size; i++)
	// 	printf("%d, ", sorted_arr[i]);
	printf("\n");
	sort_by_chunks(lst_a_info, lst_b_info, sorted_arr);
	// sort_stack(lst_a_info, lst_b_info);

	printf("%s\n", "-----------a-----------");
	print_lst(lst_a_info);
	printf("%s\n", "-----------b-----------");
	print_lst(lst_b_info);

	if (is_assending(lst_a_info))
		printf("Sorted\n");
	else
		printf("Not-Sorted\n");

	free_lst(lst_a_info);
	free_lst(lst_b_info);
}
