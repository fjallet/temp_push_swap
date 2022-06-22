/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:21:43 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/22 18:08:09 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_parsing(char **arg, t_data *data)
{
	int		i;

	i = 0;
	if (data->argc != NULL)
		arg = data->argc;
	if (ft_isstandard(arg))
	{
		ft_printf("Error\n");
		return (0);
	}
	while (arg[i])
	{
		if (ft_isint(arg[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_lstadd_back(&(data->a), ft_lstnew(ft_atoi(arg[i])));
		i++;
	}
	if (ft_checksame(data->a))
		return (0);
	return (1);
}

int	ft_isstandard(char **arg)
{
	int		i;
	int		j;
	int		witness;

	i = 0;
	j = 0;
	while (arg[i])
	{
		j = 0;
		witness = 0;
		while (arg[i][j])
		{
			if (!(arg[i][j] >= '0' && '9' >= arg[i][j]) && !(arg[i][j] \
			== '-' && j == 0))
				return (1);
			if (arg[i][j] >= '0' && '9' >= arg[i][j])
				witness = 1;
			j++;
		}
		if (witness == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isint(char *str)
{
	long	num;
	int		sig;
	int		i;

	sig = 1;
	i = 0;
	num = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (48 <= str[i] && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
		if ((sig > 0 && num > 2147483647) || (sig < 0 && num > 2147483648))
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sig;
	int	i;

	sig = 1;
	i = 0;
	num = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (48 <= str[i] && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sig);
}

int	ft_checksame(t_list *a)
{
	t_list	*i;
	t_list	*j;

	i = a;
	while (i->next != NULL)
	{
		j = i->next;
		while (j->next != NULL)
		{
			if (i->content == j->content)
			{
				ft_printf("Error\n");
				return (1);
			}
			j = j->next;
		}
		if (sub_checksame(i->content, j->content, a) == 1)
			return (1);
		i = i->next;
	}
	return (0);
}
