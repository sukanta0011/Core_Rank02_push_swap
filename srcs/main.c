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
	// int			arr[] = {29, 5, -93};
	int			arr[] = {2, 1, 3, 6, 5, 8, -33, 29, 5, -93, -47, 72, 34, -15, 43, 0, 98, -73, -9, -18, -44, 67, 86, -94, -77, -59, 82, -90, 60, -21, 61, 29, 80, -43, -38, -16, 54, 30, 63, -42, -13, -85, 80, -80, -50, -27, -29, -53, -50, 62, -20, 6, -21, -35, 13, 2, -44, -56, 12, 66, 23, -28, -5, 2, -20, 7, 36, -67, 87, -2, -58, -76, -37, -79, -56, 14, -56, -35, 11, -5, 78, 41, -100, -44, -95, -37, 8, -38, 7, -81, -73, -70, -59, -28, -18, 21, 30, -82, 5, 16};

	lst_a_info = NULL;
	lst_a_info = init_lst_info(lst_a_info);
	lst_b_info = NULL;
	lst_b_info = init_lst_info(lst_b_info);
	for (int i = 0; i < 20; i++)
		lst_a = add_at_back(lst_a_info, arr[i]);
	// lst_b = add_at_back(lst_b_info, 50);
	(void)lst_b;
	(void)lst_a;

	// push(lst_a_info, lst_b_info);
	// push(lst_a_info, lst_b_info);
	// push(lst_a_info, lst_b_info);
	// push(lst_a_info, lst_b_info);
	// rotate(lst_a_info);
	// reverse_rotate(lst_b_info);
	// push(lst_a_info, lst_b_info);
	// push(lst_a_info, lst_b_info);
	// push(lst_a_info, lst_b_info);

	sort_stack(lst_a_info, lst_b_info);

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
