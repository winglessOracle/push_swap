/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 09:22:17 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/04/03 18:02:18 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Performs radix sort. It starts by initializing the bit variable to 0
and finding the most significant bit (msb) among the integers in the stack.
It then iterates over each bit position starting from the least significant
bit (bit = 0) to the msb. For each bit position, it iterates over all
the integers in the stack and moves them to stack B if the bit 
at the current bit position is 0. It then moves all the integers
back to stack A, and increments the bit variable to move to
the next bit position.*/
void	radix_sort(t_node **stack_a, t_node **stack_b, unsigned int last_index)
{
	unsigned int	i;
	int				bit;

	bit = 0;
	while (!(is_sorted(stack_a)))
	{
		i = 0;
		while (i++ < last_index)
		{
			if (!(((*stack_a)->index >> bit & 1)))
				push('b', stack_a, stack_b);
			else
				rotate('a', stack_a, stack_b);
		}
		while (list_size(stack_b) != 0)
			push('a', stack_a, stack_b);
		bit++;
	}
}

/* determines the direction to move the elements in stack_b
based on their distance from nexts and nextb.*/
int	get_next_direction(t_node **list, unsigned int nexts, unsigned int nextb)
{
	int	dis;
	int	rev_dis;
	int	disb;
	int	rev_disb;

	dis = get_distance(list, nexts);
	disb = get_distance(list, nextb);
	rev_dis = get_distance_rev(list, nexts);
	rev_disb = get_distance_rev(list, nextb);
	if (dis > disb)
		dis = disb;
	if (rev_dis > rev_disb)
		rev_dis = rev_disb;
	if (dis > rev_dis)
		return (0);
	return (1);
}

/*moves elements from stack_a to stack_b and sorts them in descending order,
except for the elements with indexes from nexts to last_index.
These elements are rotated to the top of stack_a in ascending order.*/
int	sortatob(t_node **stack_a, t_node **stack_b, unsigned int nexts, unsigned int last_index)
{
	unsigned int	size;

	size = list_size(stack_a);
	while (size-- > 0)
	{
		if ((*stack_a)->next->index == nexts)
			swap('a', stack_a, stack_b);
		if ((*stack_a)->index == nexts)
		{
			rotate('a', stack_a, stack_b);
			nexts++;
		}
		else
		{
			push('b', stack_a, stack_b);
			if ((*stack_b)->index > last_index / 3)
				rotate('b', stack_a, stack_b);
		}
	}
	return (nexts);
}

/*moves elements from stack_b to stack_a and sorts them in ascending order.*/
void	sortbtoa(t_node **stack_a, t_node **stack_b, unsigned int nexts, unsigned int nextb)
{
	while (list_size(stack_b) > 0)
	{
		if ((*stack_b)->index == nexts)
		{
			push('a', stack_a, stack_b);
			rotate('a', stack_a, stack_b);
			nexts++;
		}
		else if ((*stack_b)->index == nextb)
		{
			push('a', stack_a, stack_b);
			nextb--;
		}
		else
		{
			if (get_next_direction(stack_b, nexts, nextb) == 1)
				rotate('b', stack_a, stack_b);
			else
				rev_rotate('b', stack_a, stack_b);
		}
	}
}

/*sorts the elements in stack_a and stack_b using ntersecting_sort.
It first sorts the elements in descending order in stack_b using sortatob,
and then sorts them in ascending order in stack_a using sortbtoa.
It then rotates stack_a until the element with index 1 is at the top.*/
void	intersect_sort(t_node **stack_a, t_node **stack_b, unsigned int last_index)
{
	unsigned int	nextb;
	unsigned int	nexts;

	nextb = last_index;
	nexts = 1;
	nexts = sortatob(stack_a, stack_b, nexts, last_index);
	sortbtoa(stack_a, stack_b, nexts, nextb);
	while ((*stack_a)->index != 1)
	{
		if (get_distance(stack_a, 1) < last_index / 2)
			rotate('a', stack_a, stack_b);
		else
			rev_rotate('a', stack_a, stack_b);
	}
}
