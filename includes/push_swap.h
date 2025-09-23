/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:53:02 by sudas             #+#    #+#             */
/*   Updated: 2025/09/22 22:53:02 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned int	t_uint;

typedef struct s_dbl_ll
{
	int				data;
	struct s_dbl_ll	*next;
	struct s_dbl_ll	*prev;
}				t_dbl_ll;

typedef struct s_dll_info
{
	t_uint		size;
	t_dbl_ll	*head;
	t_dbl_ll	*tail;
}				t_dll_info;


//======%% operation_swap %%=========
void	swap(t_dll_info *lst_info);
void	push(t_dll_info *src_info, t_dll_info *dst_info);
void	rotate(t_dll_info *lst_info);
void	reverse_rotate(t_dll_info *lst_info);

//======%% utils1 %%=========
void		dbl_ll_test(void);
t_dbl_ll	*create_node(int data);
t_dbl_ll	*add_at_back(t_dll_info *lst_info, int data);
t_dbl_ll	*add_at_front(t_dll_info *lst_info, int data);
t_dbl_ll	*del_front(t_dll_info *lst_info);
t_dll_info	*init_lst_info(t_dll_info *lst_info);
void		free_lst(t_dll_info *lst_info);

#endif