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

void	sort_three_stack (t_dll_info *lst_a, t_dll_info *lst_b)
{
	if ((lst_a->head->index > lst_a->head->next->index)
		&& (lst_a->head->index > lst_a->tail->index))
		operation(lst_a, lst_b, "ra");
	else if ((lst_a->head->next->index > lst_a->head->index)
		&& (lst_a->head->next->index > lst_a->tail->index))
		operation(lst_a, lst_b, "rra");
	else if ((lst_a->head->next->index < lst_a->head->index)
		&& (lst_a->head->next->index > lst_a->tail->index))
		operation(lst_a, lst_b, "rra");
	if (lst_a->head->index > lst_a->head->next->index)
		operation(lst_a, lst_b, "sa");
}

void	sort_stack(t_dll_info *lst_a, t_dll_info *lst_b)
{
	(void)lst_b;
	if (lst_a->size <= 3)
		sort_three_stack(lst_a, lst_b);
	if (lst_a->size > 3 && lst_a->size <= 150)
		chunk_sort(lst_a, lst_b);
	if (lst_a->size > 150)
		radix_sort(lst_a, lst_b);
}
