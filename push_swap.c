/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:22:10 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/24 15:32:06 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_move(t_list **a, t_list **b, t_move bestmove)
{
	while (bestmove.rr-- != 0)
		double_rotate(a, b);
	while (bestmove.rrr-- != 0)
		double_reverse_rotate(a, b);
	while (bestmove.ra-- != 0)
		rotate(a, 'a');
	while (bestmove.rb-- != 0)
		rotate(b, 'b');
	while (bestmove.rra-- != 0)
		reverse_rotate(a, 'a');
	while (bestmove.rrb-- != 0)
		reverse_rotate(b, 'b');
}

void	ft_pushswap(t_list **a, t_list **b)
{
	t_move	bestmove;

	while (*b)
	{
		bestmove = checkbestmove(*a, *b);
		ft_move(a, b, bestmove);
		push(b, a, 'a');
	}
	(void)bestmove;
}

void	final_rotate(t_list **a)
{
	int	pos;

	pos = find_pos_low(*a);
	if (pos <= ft_lstcount(*a) / 2)
	{
		while (pos > 0)
		{
			rotate(a, 'a');
			pos--;
		}
	}
	else
	{
		while (pos < ft_lstcount(*a))
		{
			reverse_rotate(a, 'a');
			pos++;
		}
	}
}

void	sub_main(t_data data)
{
	if (ft_is_ordoned(data.a) == 0)
	{
		get_lis(&data);
		ft_swaplis(&(data.a), &(data.b), data);
		ft_pushswap(&(data.a), &(data.b));
	}
	final_rotate(&(data.a));
	free_all(data);
}

int	main(int argv, char **argc)
{
	t_data	data;

	data_init(&data);
	data.argv = argv;
	if (argv == 2 && ft_checksplit(argc[1]) == 1)
		data.argc = ft_split(argc[1], ' ');
	else if (argv == 2 && ft_checksplit(argc[1]) == 0)
		return (0);
	if (argv < 2 || argc[1][0] == '\0')
	{
		free_all(data);
		return (0);
	}
	if (ft_parsing(&argc[1], &data) == 0 || ft_lstcount(data.a) < 2)
	{
		free_all(data);
		return (0);
	}
	if (ft_argswap(&(data.a), &(data.b)) == 0)
	{
		free_all(data);
		return (0);
	}
	sub_main(data);
	return (0);
}
