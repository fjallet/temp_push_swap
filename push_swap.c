/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:22:10 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 18:55:43 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_free(t_list **lst)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	while ((*lst)->next != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	free(*lst);
	*lst = NULL;
}

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
	int		num;
	int		pos;
	int		i;
	t_list	*temp;

	temp = *a;
	num = 2147483647;
	pos = 0;
	i = 0;
	while (i < ft_lstcount(*a))
	{
		if (num > temp->content)
		{
			num = temp->content;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	sub_final_rotate(a, pos);
}

int	main(int argv, char **argc)
{
	t_data	data;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argv == 2)
		argc = ft_split(argc[1], ' ');
	if (argv <= 2)
		return (0);
	a = ft_parsing(argc, &a);
	if (!a)
		return (1);
	data.a = a;
	if (ft_argswap(a) == 0)
	{
		stack_free(&a);
		return (0);
	}
	get_lis(&data);
	ft_swaplis(&a, &b, data);
	ft_pushswap(&a, &b);
	final_rotate(&a);
	stack_free(&a);
	stack_free((&data.lis));
	stack_free(&b);
	return (0);
}
