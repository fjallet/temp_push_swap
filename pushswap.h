/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:29:12 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 18:46:01 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list	t_list;

struct s_list {
	int		content;
	t_list	*next;
};

//t_data du backtracking
/*typedef struct s_data {
	t_list	*bestlis;
	t_list	*lis;
	int		bestcount;
	int		count;
}				t_data;*/

typedef struct s_data {
	t_list	*a;
	t_list	*trace;
	t_list	*lis;
	int		len;
	int		len_lis;
	int		pos_max;
}				t_data;

typedef struct s_move {
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	num;
}				t_move;

//push_swap.c
void	stack_free(t_list **lst);
void	ft_move(t_list **a, t_list **b, t_move bestmove);
void	final_rotate(t_list **a);
void	ft_pushswap(t_list **a, t_list **b);

//ft_parsing.c
t_list	*ft_parsing(char **arg, t_list	**a);
int		ft_isstandard(char **arg);
int		ft_isint(char *arg);
int		ft_atoi(const char *str);
int		ft_checksame(t_list *a);

//push_swap_utils.c
void	ft_lstcpy(t_list **lst, t_list **new);
void	print_stack(t_list *lst);
void	swap(t_list **a, char c);
void	double_swap(t_list **a, t_list **b);
int		ft_isnotlis(int a, t_data data);

//ft_stack_utils.c
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstcount(t_list *lst);

//operation.c
void	push(t_list **a, t_list **b, char c);
void	rotate(t_list **a, char c);
void	double_rotate(t_list **a, t_list **b);
void	reverse_rotate(t_list **a, char c);
void	double_reverse_rotate(t_list **a, t_list **b);

//ft_lis.c
/*t_data	*ft_initdata(t_list *lst, t_data *data);
t_data	*ft_lis(t_list *lst, t_data *data);
t_data	*ft_inclis(t_list *lst, t_data *data);
int		ft_isnotlis(int a, t_data data);
void	ft_swaplis(t_list **a, t_list **b, t_data data);*/

//ft_new_lis.c
t_list	*find_box(t_list *a, int b);
void	find_lis_trace(t_data *d);
void	init_t_data(t_data *d);
void	get_lis(t_data *d);
void	ft_swaplis(t_list **a, t_list **b, t_data d);

//ft_checkbestmove.c
t_move	checkbestmove(t_list *a, t_list *b);
void	movecreate(t_move posia, t_move posib, t_move *tempmove);
void	ft_rrp(t_move posia, t_move posib, t_move *tempmove);
void	ft_rrrp(t_move posia, t_move posib, t_move *tempmove);
void	ft_swaprrp(t_move posia, t_move posib, t_move *tempmove);

//ft_divers.c
void	ft_initmove(t_move *a);
void	sub_final_rotate(t_list **a, int pos);
int		sub_checksame(int i, int j, t_list *a);
int		ft_is_ordoned_absolute(t_list *a);
int		ft_is_ordoned(t_list *a);

//ft_posi.c
void	ft_posiup(t_list *a, int *count);
void	ft_posilim(int b, t_list *a, int *count);
void	ft_posi(int b, t_list *a, t_move *posi);
int		getmin(int a, int b);
int		getmax(int a, int b);

//ft_split.c
char	**ft_split(char const *s, char c);

//ft_lowarg.c
int 	ft_argswap(t_list *a);
void 	ft_arg3(t_list *a);

#endif