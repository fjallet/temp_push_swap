/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbestmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:26:12 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 13:23:04 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_move	checkbestmove(t_list *a, t_list *b)
{
	t_move	posib;
	t_move	posia;
	t_move	bestmove;
	t_move	tempmove;
	int		range;

	ft_initmove(&posib);
	ft_initmove(&posia);
	ft_initmove(&bestmove);
	range = ft_lstcount(b);
	while (posib.rr < range)
	{
		ft_initmove(&tempmove);
		ft_posi(b->content, a, &posia);
		posib.rrr = range - posib.rr;
		if (range == 1)
			posib.rrr = 0;
		movecreate(posia, posib, &tempmove);
		if (tempmove.num < bestmove.num)
			bestmove = tempmove;
		b = b->next;
		posib.rr++;
	}
	return (bestmove);
}

void	movecreate(t_move posia, t_move posib, t_move *tempmove)
{
	t_move	mini;
	t_move	maxi;

	mini.rr = getmin(posia.rr, posib.rr);
	mini.rrr = getmin(posia.rrr, posib.rrr);
	maxi.rr = getmax(posia.rr, posib.rr);
	maxi.rrr = getmax(posia.rrr, posib.rrr);
	if (maxi.rr > (mini.rr + mini.rrr) && maxi.rrr > (mini.rr + mini.rrr))
		ft_swaprrp(posia, posib, tempmove);
	else if (maxi.rr <= maxi.rrr)
		ft_rrp(posia, posib, tempmove);
	else if (maxi.rr >= maxi.rrr)
		ft_rrrp(posia, posib, tempmove);
}

void	ft_rrp(t_move posia, t_move posib, t_move *tempmove)
{
	if (tempmove->num < posib.rr && tempmove->num < posia.rr)
		return ;
	if (posib.rr >= posia.rr)
	{
		tempmove->rr = posia.rr;
		tempmove->rb = posib.rr - posia.rr;
		tempmove->num = posib.rr;
	}	
	else if (posib.rr < posia.rr)
	{
		tempmove->rr = posib.rr;
		tempmove->ra = posia.rr - posib.rr;
		tempmove->num = posia.rr;
	}
}

void	ft_rrrp(t_move posia, t_move posib, t_move *tempmove)
{
	if (tempmove->num < posib.rrr && tempmove->num < posia.rrr)
		return ;
	if (posib.rrr >= posia.rrr)
	{
		tempmove->rrr = posia.rrr;
		tempmove->rrb = posib.rrr - posia.rrr;
		tempmove->num = posib.rrr;
	}	
	else if (posib.rrr < posia.rrr)
	{
		tempmove->rrr = posib.rrr;
		tempmove->rra = posia.rrr - posib.rrr;
		tempmove->num = posia.rrr;
	}
}

void	ft_swaprrp(t_move posia, t_move posib, t_move *tempmove)
{
	if (posia.rr + posib.rrr >= posia.rrr + posib.rr)
	{
		if (tempmove->num > posib.rr + posia.rrr)
		{
			tempmove->rra = posia.rrr;
			tempmove->rb = posib.rr;
			tempmove->num = posib.rr + posia.rrr;
		}
	}
	else
	{
		if (tempmove->num > posib.rrr + posia.rr)
		{
			tempmove->ra = posia.rr;
			tempmove->rrb = posib.rrr;
			tempmove->num = posib.rrr + posia.rr;
		}
	}
}
