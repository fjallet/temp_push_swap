/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_lis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:08:26 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 15:06:29 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*find_box(t_list *a, int b)
{
	while (a->next != NULL && b-- > 0)
		a = a->next;
	return (a);
}

void	find_lis_trace(t_data *d)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i++ < d->len)
		ft_lstadd_front(&(d->trace), ft_lstnew(1));
	i = 1;
	while (i < d->len)
	{
		j = 0;
		while (j < i)
		{
			if (find_box(d->a, i)->content > find_box(d->a, j)->content && \
			find_box(d->trace, i)->content < find_box(d->trace, j)->content + 1)
			{
				temp = find_box(d->trace, j)->content + 1;
				find_box(d->trace, i)->content = temp;
			}
			j++;
		}
		i++;
	}
}

void	init_t_data(t_data *d)
{
	int	i;

	d->trace = NULL;
	d->len = ft_lstcount(d->a);
	find_lis_trace(d);
	d->len_lis = 0;
	i = 0;
	while (i < d->len)
	{
		if (d->len_lis < find_box(d->trace, i)->content)
		{
			d->len_lis = find_box(d->trace, i)->content;
			d->pos_max = i;
		}
		i++;
	}
}

void	get_lis(t_data *d)
{
	int	i;
	int	j;

	init_t_data(d);
	i = d->pos_max;
	j = i - 1;
	d->lis = NULL;
	ft_lstadd_front(&(d->lis), ft_lstnew(find_box(d->a, i)->content));
	while (j >= 0)
	{
		if ((find_box(d->trace, i)->content - find_box(d->trace, j)->content) \
		== 1)
		{
			ft_lstadd_front(&(d->lis), ft_lstnew(find_box(d->a, j)->content));
			i = j;
		}
		j--;
	}
}

void	ft_swaplis(t_list **a, t_list **b, t_data d)
{
	int		range;

	range = ft_lstcount(*a);
	while (range > 0)
	{
		if (ft_isnotlis((*a)->content, d))
			push(a, b, 'b');
		else
		{
			rotate(a, 'a');
		}
		range--;
	}
	stack_free(&(d.trace));
}
