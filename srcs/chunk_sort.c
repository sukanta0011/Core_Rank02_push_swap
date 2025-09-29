/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:54:26 by sudas             #+#    #+#             */
/*   Updated: 2025/09/29 14:54:26 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_chunk_size (int size)
{
	if (size <= 7)
		return (2);
	if (size > 7 && size <= 10)
		return (4);
	if (size > 10 && size <= 40)
		return (10);
	if (size > 40 && size <= 100)
		return (20);
	if (size > 100)
		return (40);
	return (-1);
}

void	push_single_value(t_dll_info *lst_a, t_dll_info *lst_b,
		int low, int high)
{
	int	top_dist;
	int	bottom_dist;

	top_dist = find_from_top(lst_a, low, high);
	bottom_dist = find_from_bottom(lst_a, low, high);
	if (top_dist <= bottom_dist)
		while (top_dist-- > 0)
			operation(lst_a, lst_b, "ra");
	else
		while (bottom_dist-- > 0)
			operation(lst_a, lst_b, "rra");
	operation(lst_a, lst_b, "pb");
	if (lst_b->size > 1 && lst_b->head->index < (low + high) / 2)
		operation(lst_a, lst_b, "rb");
}

void	empty_stack_b(t_dll_info *lst_a, t_dll_info *lst_b)
{
	int	idx;
	int	moves;

	while (lst_b->size > 0)
	{
		idx = find_largest_in_b(lst_b);
		if (idx <= lst_b->size / 2)
			while (idx-- > 0)
				operation(lst_a, lst_b, "rb");
		else
		{
			moves = lst_b->size - idx;
			while (moves-- > 0)
				operation(lst_a, lst_b, "rrb");
		}
		operation(lst_a, lst_b, "pa");
	}
}

void	reassign_low_high(int *low, int *high, int *pushed_in_chunk, int *n)
{
	(*pushed_in_chunk) = 0;
	(*low) += cal_chunk_size(*n);
	(*high) += cal_chunk_size(*n);
	if ((*high) >= (*n))
		(*high) = (*n) - (*low);
}

void	chunk_sort(t_dll_info *lst_a, t_dll_info *lst_b)
{
	int	n;
	int	low;
	int	high;
	int	pushed_in_chunk;
	int	empty_lst_a_till;

	pushed_in_chunk = 0;
	n = lst_a->size;
	empty_lst_a_till = 0;
	low = 0;
	high = cal_chunk_size(n) - 1;
	if (n <= 7)
		empty_lst_a_till = 3;
	while (lst_a->size > empty_lst_a_till)
	{
		push_single_value(lst_a, lst_b, low, high);
		pushed_in_chunk++;
		if (pushed_in_chunk == cal_chunk_size(n))
			reassign_low_high(&low, &high, &pushed_in_chunk, &n);
	}
	if (empty_lst_a_till > 0)
		sort_three_stack(lst_a, lst_b);
	empty_stack_b(lst_a, lst_b);
}
