/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 19:31:09 by carlo         #+#    #+#                 */
/*   Updated: 2023/04/03 18:02:02 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	find_highest_3(t_node **list)
{
	unsigned int	high;
	int				count;
	t_node			*curr;

	high = 0;
	count = 0;
	curr = *list;
	while (count < 3)
	{
		if (curr->index > high)
			high = curr->index;
		curr = curr->next;
		count++;
	}
	return (high);
}

void	simple_3(t_node **stack_a, t_node **stack_b)
{
	unsigned int	high;

	if (is_sorted(stack_a) && list_size(stack_b) == 0)
		return ;
	high = find_highest_3(stack_a);
	if ((*stack_a)->index == high)
		rotate('a', stack_a, stack_b);
	else if ((*stack_a)->next->index == high)
		rev_rotate('a', stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap('a', stack_a, stack_b);
}

void	simple_4(t_node **stack_a, t_node **stack_b)
{
	int		distance;

	if (is_sorted(stack_a) && list_size(stack_b) == 0)
		return ;
	distance = get_distance(stack_a, 1);
	if (distance == 1)
		rotate('a', stack_a, stack_b);
	if (distance == 2)
	{
		rotate('a', stack_a, stack_b);
		rotate('a', stack_a, stack_b);
	}
	if (distance == 3)
		rev_rotate('a', stack_a, stack_b);
	if (is_sorted(stack_a))
		return ;
	push('b', stack_a, stack_b);
	simple_3(stack_a, stack_b);
	push('a', stack_a, stack_b);
}

void	simple_5(t_node **stack_a, t_node **stack_b)
{
	int		distance;

	if (is_sorted(stack_a) && list_size(stack_b) == 0)
		return ;
	distance = get_distance(stack_a, 2);
	if (distance == 1)
		rotate('a', stack_a, stack_b);
	if (distance == 2)
	{
		rotate('a', stack_a, stack_b);
		rotate('a', stack_a, stack_b);
	}
	if (distance == 3)
	{
		rev_rotate('a', stack_a, stack_b);
		rev_rotate('a', stack_a, stack_b);
	}
	if (distance == 4)
		rev_rotate('a', stack_a, stack_b);
	if (is_sorted(stack_a))
		return ;
	push('b', stack_a, stack_b);
	simple_4(stack_a, stack_b);
	push('a', stack_a, stack_b);
	swap('a', stack_a, stack_b);
}
