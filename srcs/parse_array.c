/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:52:32 by sudas             #+#    #+#             */
/*   Updated: 2025/09/27 00:52:32 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_dll_info *lst, int *sorted)
{
	t_dbl_ll *current;

	current = lst->head;
	while (current)
	{
		current->index = find_index(sorted,
				current->data, 0, lst->size - 1);
		current = current->next;
	}
}

int	store_in_stack(int argc, char **argv, t_dll_info *lst_info)
{
	int	i;
	int	num[1];

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (str_to_num(argv[i], num))
		{
			add_at_back(lst_info, num);
			i++;
		}
		else
			return (0);
	}
	return (1);
}