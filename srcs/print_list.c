/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 00:05:10 by sudas             #+#    #+#             */
/*   Updated: 2025/09/24 00:05:10 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_dll_info *lst_info)
{
	t_dbl_ll	*temp;

	if (!lst_info->head)
		return ;
	printf ("Head: %d, Tail: %d, size: %d\n",
		lst_info->head->data,
		lst_info->tail->data,
		lst_info->size);
	temp = lst_info->head;
	while (temp)
	{
		printf ("%d\n", temp->data);
		temp = temp->next;
	}
}

void	print_lst_reverse(t_dll_info *lst_info)
{
	t_dbl_ll	*temp;

	if (!lst_info->head)
		return ;
	printf ("Head: %d, Tail: %d, size: %d\n",
		lst_info->head->data,
		lst_info->tail->data,
		lst_info->size);
	temp = lst_info->tail;
	while (temp)
	{
		printf ("%d\n", temp->data);
		temp = temp->prev;
	}
}
