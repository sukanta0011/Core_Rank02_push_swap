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
	int			arr[] = {10, 5, 15, 20, -5, '\0'};

	lst_a_info = NULL;
	lst_a_info = init_lst_info(lst_a_info);
	lst_b_info = NULL;
	lst_b_info = init_lst_info(lst_b_info);
	for (int i = 0; arr[i]; i++)
		lst_a = add_at_back(lst_a_info, arr[i]);
	lst_b = add_at_back(lst_b_info, 50);
	(void)lst_b;
	(void)lst_a;

	push(lst_a_info, lst_b_info);
	push(lst_a_info, lst_b_info);
	push(lst_a_info, lst_b_info);
	// push(lst_a_info, lst_b_info);
	rotate(lst_a_info);
	reverse_rotate(lst_b_info);
	// push(lst_a_info, lst_b_info);
	// push(lst_a_info, lst_b_info);
	// push(lst_a_info, lst_b_info);

	printf("%s\n", "-----------a-----------");
	print_lst(lst_a_info);
	printf("%s\n", "-----------b-----------");
	print_lst(lst_b_info);

	printf("%s\n", "-----------ra-----------");
	print_lst_reverse(lst_a_info);
	printf("%s\n", "-----------rb-----------");
	print_lst_reverse(lst_b_info);
	
	free_lst(lst_a_info);
	free_lst(lst_b_info);
}
