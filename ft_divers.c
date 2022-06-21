/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:03:17 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 18:30:06 by fjallet          ###   ########.fr       */
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

void	sub_final_rotate(t_list **a, int pos)
{
	while (pos > 0)
	{
		if (pos <= ft_lstcount(*a))
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
		pos--;
	}
}

int	sub_checksame(int i, int j, t_list *a)
{
	if (i == j)
	{
		ft_printf("Error\n");
		stack_free(&a);
		return (1);
	}
	return (0);
}

int	ft_is_ordoned(t_list *a)
{
	t_list	*temp;
	int		num;
	int		i;
	int		pos;

	temp = a;
	i = 0;
	num = 2147483647;
	while (i++ < ft_lstcount(a))
	{
		if (num > temp->content)
		{
			num = temp->content;
			pos = i;
		}
		temp = temp->next;
	}
	temp = a;
	while(i-- > 0)
	{
		if (temp->content > temp->next->content && i != pos)
			return (0);
	}
	return (1);
}

int	ft_is_ordoned_absolute(t_list *a)
{
	while (a->next != 0)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}