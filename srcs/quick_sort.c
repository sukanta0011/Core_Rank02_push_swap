/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:28:22 by sudas             #+#    #+#             */
/*   Updated: 2025/09/26 10:28:22 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_values(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_uint	swap_array_elements(int *arr, t_uint low, t_uint high)
{
	t_uint	i;
	t_uint	j;
	int		pivot_value;

	i = low;
	j = low;
	pivot_value = arr[high];
	while (j < high)
	{
		if (arr[j] < pivot_value)
		{
			swap_values(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap_values(&arr[i], &arr[high]);
	return (i);
}

void	quick_sort(int *arr, t_uint low, t_uint high)
{
	if (low < high)
	{
		t_uint	pivot;
		
		pivot = swap_array_elements(arr, low, high);
		if (pivot > 0)
			quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}