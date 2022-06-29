/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:31:35 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/24 15:23:58 by fjallet          ###   ########.fr       */
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

void	tab_free(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (data->argv != 2)
		return ;
	while (data->argc[len] != NULL)
		len++;
	while (i < len)
	{
		free(data->argc[i]);
		i++;
	}
	free(data->argc);
}

void	free_all(t_data data)
{
	tab_free(&data);
	stack_free(&(data.a));
	stack_free(&(data.lis));
	stack_free(&(data.b));
}

int	ft_checksplit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
