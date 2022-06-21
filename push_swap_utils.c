/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:51:00 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 14:32:24 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstcpy(t_list **lst, t_list **new)
{
	t_list	*temp;

	*new = NULL;
	if (!(*lst))
		return ;
	temp = *lst;
	while (temp->next != NULL)
	{
		ft_lstadd_back(new, ft_lstnew(temp->content));
		temp = temp->next;
	}
	ft_lstadd_back(new, ft_lstnew(temp->content));
}

void	print_stack(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = lst;
	while (temp->next != NULL)
	{
		ft_printf("%i\n", temp->content);
		temp = temp->next;
	}
	ft_printf("%i\n", temp->content);
}

void	swap(t_list **a, char c)
{
	t_list	*temp;

	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	ft_printf("s%c\n", c);
}

void	double_swap(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	ft_printf("ss\n");
}

int	ft_isnotlis(int a, t_data data)
{
	t_list	*temp;
	int		range;

	range = ft_lstcount(data.lis);
	temp = data.lis;
	while (range > 0)
	{
		if (temp->content == a)
		{
			return (0);
		}
		temp = temp->next;
		range--;
	}
	return (1);
}
