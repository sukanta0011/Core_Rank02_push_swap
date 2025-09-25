#include "push_swap.h"

void	sort_stack(t_dll_info *lst_a, t_dll_info *lst_b)
{
	t_uint	steps;

	steps = 0;
	(void)lst_b;
	while (lst_a->size > 1)
	{
		while ((lst_a->head->data > lst_a->tail->data)
			|| (lst_a->head->data > lst_a->head->next->data))
		{
			if (lst_a->head->data > lst_a->tail->data)
			{
				operation (lst_a, lst_b, "ra");
				steps++;
			}
			if ((lst_a->head->data > lst_a->head->next->data))
			{
				operation(lst_a, lst_b, "sa");
				steps++;
			}
		}
		operation(lst_a, lst_b, "pb");
		steps++;
		if (lst_b->size > 1)
		{
			while ((lst_b->head->data < lst_b->tail->data)
				|| (lst_b->head->data < lst_b->head->next->data))
			{
				if (lst_b->head->data < lst_b->tail->data)
				{
					operation (lst_a, lst_b, "rb");
					steps++;
				}
				if ((lst_b->head->data < lst_b->head->next->data))
				{
					operation(lst_a, lst_b, "sb");
					steps++;
					operation(lst_a, lst_b, "pa");
					steps++;
				}
			}
		}
	}
	while (lst_b->size)
	{
		operation(lst_a, lst_b, "pa");
		steps++;
	}
	printf("Steps : %u\n", steps);
}
