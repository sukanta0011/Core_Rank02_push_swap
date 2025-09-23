/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:09:19 by sudas             #+#    #+#             */
/*   Updated: 2025/09/22 23:09:19 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_dbl_ll	*create_node(int data)
{
	t_dbl_ll	*new_node;

	new_node = malloc(sizeof(t_dbl_ll));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_dbl_ll	*add_at_back(t_dll_info *lst_info, int data)
{
	t_dbl_ll	*temp;
	t_dbl_ll	*new_node;

	new_node = create_node(data);
	temp = lst_info->tail;
	if (temp)
	{
		lst_info->tail = new_node;
		new_node->prev = temp;
		temp->next = new_node;
	}
	else
	{
		lst_info->head = new_node;
		lst_info->tail = new_node;
	}
	lst_info->size++;
	return (lst_info->head);
}

t_dbl_ll	*add_at_front(t_dll_info *lst_info, int data)
{
	t_dbl_ll	*temp;
	t_dbl_ll	*new_node;

	new_node = create_node(data);
	temp = lst_info->head;
	if (temp)
	{
		lst_info->head = new_node;
		temp->prev = new_node;
		new_node->next = temp;
	}
	else
	{
		lst_info->head = new_node;
		lst_info->tail = new_node;
	}
	lst_info->size++;
	return (lst_info->head);
}

void	dbl_ll_test(void)
{
	t_dbl_ll	*lst_a;
	// t_dbl_ll	*lst_b;
	t_dll_info	*lst_a_info;
	t_dbl_ll	*a;
	t_dbl_ll	*b;
	t_dbl_ll	*c;

	lst_a_info = malloc(sizeof(t_dll_info));
	a = create_node(5);
	b = create_node(10);
	c = create_node(3);

	lst_a = a;
	lst_a->next = b;
	lst_a->prev = NULL;
	lst_a->next->next = c;
	lst_a->next->prev = a;
	lst_a->next->next->prev = b;

	printf("%s\n", "-----------a-----------");
	lst_a_info->head = lst_a;
	while (lst_a->next)
	{
		printf("%d\n", lst_a->data);
		lst_a = lst_a->next;
	}
	printf("%d\n", lst_a->data);
	lst_a_info->tail = lst_a;
	lst_a = lst_a_info->head;
	lst_a_info->size = 3;

	printf("%d\n", lst_a_info->tail->data);
}