/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:31:54 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/22 19:59:04 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_argswap(t_list **a)
{
	if (ft_is_ordoned_absolute(*a) == 0)
		return (0);
	if (ft_lstcount(*a) == 2)
	{
		ft_printf("ra\n");
		return (0);
	}
	if (ft_lstcount(*a) == 3)
	{
		ft_arg3(a);
		return (0);
	}
	return (1);
}

void	ft_arg3(t_list **a)
{
	if (ft_is_ordoned(*a) == 1)
		final_rotate(a);
	else
	{
		swap(a, 'a');
		final_rotate(a);
	}
	(void)a;
}

int	ft_is_ordoned(t_list *a)
{
	t_list	*temp;
	int		pos;
	int		i;

	pos = find_pos_low(a);
	temp = a;
	i = ft_lstcount(a);
	pos = i - pos;
	if (temp->content < ft_lstlast(a)->content && pos != i)
	{
		return (0);
	}
	while (i-- > 1)
	{
		if (temp->content > temp->next->content && i != pos)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_is_ordoned_absolute(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp->next != 0)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	low_rotate(t_list *a)
{
	int	pos;

	pos = find_pos_low(a);
	if (pos <= ft_lstcount(a) / 2)
	{
		while (pos > 0)
		{
			ft_printf("ra\n");
			pos--;
		}
	}
	else
	{
		while (pos < ft_lstcount(a))
		{
			ft_printf("ra\n");
			pos++;
		}
	}
}
