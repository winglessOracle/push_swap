/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_push.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 15:22:34 by carlo         #+#    #+#                 */
/*   Updated: 2023/04/03 18:02:30 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the first two elements of stack 'a' or 'b', 
or both. */
int	swap(char ident, t_node **stack_a, t_node **stack_b)
{
	if (ident == 'a')
		if (swap_first(stack_a))
			ft_putstr("sa\n");
	if (ident == 'b')
		if (swap_first(stack_b))
			ft_putstr("sb\n");
	if (ident == 's')
		if (swap_first(stack_a) && swap_first(stack_b))
			ft_putstr("ss\n");
	return (1);
}

/* Performs the actual swap operation by swapping the first two 
elements of the given stack 'list'. */
int	swap_first(t_node **list)
{
	t_node	*temp;

	if (*list == NULL)
		return (0);
	temp = *list;
	*list = (*list)->next;
	temp->next = (*list)->next;
	(*list)->next = temp;
	return (1);
}

/* Pushes the top element from stack 'a' to stack 'b'
or vice versa. */
int	push(char ident, t_node **stack_a, t_node **stack_b)
{
	if (ident == 'a')
		if (push_top(stack_a, stack_b))
			ft_putstr("pa\n");
	if (ident == 'b')
		if (push_top(stack_b, stack_a))
			ft_putstr("pb\n");
	return (0);
}

/* Performs the actual push operation by moving the top element
from 'src' to 'dst'. */
int	push_top(t_node **dst, t_node **src)
{
	t_node	*temp;

	if (*src == NULL)
		return (0);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
	return (1);
}
