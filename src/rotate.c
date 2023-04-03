/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 22:16:25 by carlo         #+#    #+#                 */
/*   Updated: 2023/04/03 18:01:55 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates stack 'a' or 'b' by moving the top element to
the bottom of the stack. */
int	rotate(char ident, t_node **stack_a, t_node **stack_b)
{
	if (ident == 'a')
	{
		rotate_up(stack_a);
		ft_putstr("ra\n");
	}
	if (ident == 'b')
	{
		rotate_up(stack_b);
		ft_putstr("rb\n");
	}
	if (ident == 'r')
	{
		rotate_up(stack_a);
		rotate_up(stack_b);
		ft_putstr("rr\n");
	}
	return (0);
}

/* Rotates stack 'a' or 'b' by moving the bottom element
to the top of the stack. */
int	rev_rotate(char ident, t_node **stack_a, t_node **stack_b)
{
	if (ident == 'a')
	{
		rotate_down(stack_a);
		ft_putstr("rra\n");
	}
	if (ident == 'b')
	{
		rotate_down(stack_b);
		ft_putstr("rrb\n");
	}
	if (ident == 'r')
	{
		rotate_down(stack_a);
		rotate_down(stack_b);
		ft_putstr("rrr\n");
	}
	return (0);
}

/* Performs the actual rotation up operation by moving the
top element to the bottom of the given stack. */
int	rotate_up(t_node **list)
{
	t_node	*curr;

	if (*list == NULL)
		return (0);
	curr = *list;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *list;
	*list = (*list)->next;
	curr->next->next = NULL;
	return (0);
}

/* Performs the actual rotation down operation
by moving the bottom element to the top of
the given stack. */
int	rotate_down(t_node **list)
{
	t_node	*last;
	t_node	*curr;

	if (*list == NULL)
		return (0);
	curr = *list;
	last = NULL;
	while (curr->next->next != NULL)
		curr = curr->next;
	last = curr;
	curr = curr->next;
	curr->next = *list;
	*list = curr;
	last->next = NULL;
	return (0);
}
