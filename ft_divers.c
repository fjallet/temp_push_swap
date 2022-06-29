/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:03:17 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/24 15:39:54 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_initmove(t_move *a)
{
	a->ra = 0;
	a->rb = 0;
	a->rr = 0;
	a->rra = 0;
	a->rrb = 0;
	a->rrr = 0;
	a->num = 1000;
}

int	find_pos_low(t_list *a)
{	
	int		num;
	int		pos;
	int		i;
	t_list	*temp;

	temp = a;
	num = 2147483647;
	pos = 0;
	i = 0;
	while (i < ft_lstcount(a))
	{
		if (num > temp->content)
		{
			num = temp->content;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

int	sub_checksame(int i, int j, t_list *a)
{
	if (i == j)
	{
		ft_printf("Error\n");
		return (1);
	}
	(void)a;
	return (0);
}

void	data_init(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->trace = NULL;
	data->lis = NULL;
	data->argc = NULL;
	(void)data;
}

void	ft_5arg(t_list **a, t_list **b)
{
	push(a, b, 'b');
	push(a, b, 'b');
	ft_arg3(a);
	ft_pushswap(a, b);
	final_rotate(a);
}
