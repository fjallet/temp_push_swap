/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:31:54 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 18:46:56 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int ft_argswap(t_list *a)
{
    if (ft_is_ordoned_absolute(a) == 0)
        return (0);
    if (ft_lstcount(a) == 2)
    {
        final_rotate(&a);
        return (0);
    }
    if (ft_lstcount(a) == 3)
    {
        ft_arg3(a);
        return (0);
    }
    return (1);
}

void ft_arg3(t_list *a)
{
    if (ft_is_ordoned(a))
        final_rotate(&a);
    else
    {
        swap(&a, 'a');
        final_rotate(&a);
    }
    (void)a;
}