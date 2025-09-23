#include "push_swap.h"

void	free_lst(t_dll_info *lst_info)
{
	t_dbl_ll	*temp;
	t_dbl_ll	*next;

	temp = lst_info->head;
	while (temp)
	{
		next = temp->next;
		free (temp);
		temp = next;
	}
	free(lst_info);
}

t_dbl_ll	*del_front(t_dll_info *lst_info)
{
	t_dbl_ll	*temp;

	if (!lst_info || !lst_info->head)
        return (NULL);
	temp = lst_info->head;
	if(lst_info->size > 1)
	{
		lst_info->head = temp->next;
		lst_info->head->prev = NULL;
		// temp->next = NULL;
	}
	else
	{
		lst_info->head = NULL;
		lst_info->tail = NULL;
	}
	free(temp);
	lst_info->size--;
	return (lst_info->head);
}

int	main(void)
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
		printf("%d: %p\n", lst_a->data, lst_a);
		lst_a = lst_a->next;
	}
	printf("%d: %p\n", lst_a->data, lst_a);
	lst_a_info->tail = lst_a;
	lst_a = lst_a_info->head;
	
	lst_a = add_at_back(lst_a_info, 15);
	lst_a = add_at_front(lst_a_info, -15);
	lst_a = del_front(lst_a_info);

	printf("%s\n", "-----------append-----------");
	lst_a_info->head = lst_a;
	while (lst_a->next)
	{
		printf("%d\n", lst_a->data);
		lst_a = lst_a->next;
	}
	printf("%d\n", lst_a->data);
	lst_a = lst_a_info->head;
	free_lst(lst_a_info);
}