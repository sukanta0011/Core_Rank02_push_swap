/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:49:34 by sudas             #+#    #+#             */
/*   Updated: 2025/09/26 13:49:34 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_in_chunk(int *arr, t_uint low, t_uint high, int value)
{
	while (low < high)
	{
		if (value == arr[low])
			return (1);
		low++;	
	}
	return (0);
}

int find_from_top(t_dll_info *lst_a, int *sorted, int low, int high)
{
    t_dbl_ll *cur = lst_a->head;
    int idx = 0;

    while (cur)
    {
        if (cur->data >= sorted[low] && cur->data <= sorted[high])
            return idx;
        cur = cur->next;
        idx++;
    }
    return -1;
}

int find_from_bottom(t_dll_info *lst_a, int *sorted, int low, int high)
{
    t_dbl_ll *cur = lst_a->tail;
    int idx = 0;

    while (cur)
    {
        if (cur->data >= sorted[low] && cur->data <= sorted[high])
            return idx;
        cur = cur->prev;
        idx++;
    }
    return -1;
}

int find_largest_in_b(t_dll_info *lst_b)
{
    t_dbl_ll *cur = lst_b->head;
    int idx = 0, best_idx = 0;
    int max = cur->data;

    while (cur)
    {
        if (cur->data > max)
        {
            max = cur->data;
            best_idx = idx;
        }
        cur = cur->next;
        idx++;
    }
    return best_idx;
}

void sort_by_chunks(t_dll_info *lst_a, t_dll_info *lst_b, int *sorted)
{
    int	top_dist;
	int	bottom_dist;
	int	n;
    int	chunk_size;
    int	low;
    int	high;
	int	idx;
	int	steps;
	int pushed_in_chunk = 0;

    n =  lst_a->size;
	chunk_size = 3;
	low = 0;
	high = chunk_size - 1;
	steps = 0;
	while (lst_a->size > 0)
    {
        top_dist = find_from_top(lst_a, sorted, low, high);
        bottom_dist = find_from_bottom(lst_a, sorted, low, high);

        if (top_dist <= bottom_dist)
            while (top_dist-- > 0)
			{
                operation(lst_a, lst_b, "ra");
				steps++;
			}
        else
            while (bottom_dist-- > 0)
			{
				operation(lst_a, lst_b, "rra");
				steps++;
			}
        operation(lst_a, lst_b, "pb");
		pushed_in_chunk++;
		steps++;
        if (lst_b->size > 1 && lst_b->head->data < sorted[(low + high) / 2])
        {
			operation(lst_a, lst_b, "rb");
			steps++;
		}
        if (pushed_in_chunk == chunk_size)
        {
            pushed_in_chunk = 0;
			low += chunk_size;
            high += chunk_size;
            if (high >= n)
                high = n - low;
        }
    }
    while (lst_b->size > 0)
    {
        idx = find_largest_in_b(lst_b);

        if (idx <= lst_b->size / 2)
            while (idx-- > 0)
            {
				operation(lst_a, lst_b, "rb");
				steps++;
			}
        else
		{
			int moves = lst_b->size - idx;
    		while (moves-- > 0)
			{
				operation(lst_a, lst_b, "rrb");
				steps++;
			}
		}
        operation(lst_a, lst_b, "pa");
		steps++;
    }
	printf("Steps : %u\n", steps);
}

void	radix_sort(t_dll_info *lst_a, t_dll_info *lst_b)
{
	int i;
	int max_bits;
	int	arr_size;
	int	counts;
	int steps;

	max_bits = 0;
	steps = 0;
	i = 0;
	arr_size = lst_a->size;
	while ((arr_size >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		counts = 0;
		while (counts < arr_size)
		{
			if (((lst_a->head->index >> i) & 1) == 0)
				operation(lst_a, lst_b, "pb");
			else
				operation(lst_a, lst_b, "ra");
			counts++;
			steps++;
		}
		while (lst_b->size > 0)
		{
			operation(lst_a, lst_b, "pa");
			steps++;
		}
		i++;
	}
	printf("Steps : %u\n", steps);
}

void	sort_small_stack(t_dll_info *lst_a, t_dll_info *lst_b)
{
	(void)lst_b;
	if (lst_a->size == 2)
	{
		if (lst_a->head->data > lst_a->head->next->data)
			operation(lst_a, lst_b, "sa");
	}
	if (lst_a->size == 3)
	{
		while (lst_a->tail->index != 2)
			operation(lst_a, lst_b, "ra");
		if (lst_a->head->index != 0)
			operation(lst_a, lst_b, "sa");
	}
}
