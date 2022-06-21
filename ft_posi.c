/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_posi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:58:40 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/17 17:01:44 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_posiup(t_list *a, int *count)
{
	int		upnum;
	t_list	*temp;

	temp = a;
	upnum = -2147483648;
	while (temp)
	{
		if (upnum < temp->content)
			upnum = temp->content;
		temp = temp->next;
	}
	*count = 1;
	while (a && upnum != a->content)
	{
		(*count)++;
		a = a->next;
	}
}

void	ft_posilim(int b, t_list *a, int *count)
{
	t_list	*temp;
	int		range;
	int		up;
	int		down;

	temp = a;
	up = 0;
	down = 0;
	range = ft_lstcount(a);
	while (range-- > 0)
	{
		if (b > temp->content)
			up = 1;
		if (b < temp->content)
			down = 1;
		temp = temp->next;
	}
	if (up == 1 && down == 0)
		ft_posiup(a, count);
	if (up == 0 && down == 1)
		ft_posiup(a, count);
	if (a->content > b && b > (ft_lstlast(a))->content)
		*count = 0;
}

void	ft_posi(int b, t_list *a, t_move *posi)
{
	int		count;
	int		range;
	t_list	*temp;

	count = 0;
	temp = a;
	range = ft_lstcount(a);
	while (count < range - 1)
	{
		count++;
		if (temp->content < b && b < temp->next->content)
			break ;
		temp = temp->next;
	}
	ft_posilim(b, a, &count);
	posi->rr = count;
	posi->rrr = range - count;
}

int	getmin(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

int	getmax(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
