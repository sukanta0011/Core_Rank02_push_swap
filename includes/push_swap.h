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
	int			data;
	t_dbl_ll	*next;
	t_dbl_ll	*prev;
}				t_dbl_ll;


//======%% operation_swap %%=========
void	swap(int *arr);

//======%% utils1 %%=========
t_uint	arr_len(int *arr);

#endif