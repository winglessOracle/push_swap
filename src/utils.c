/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 12:40:54 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/04/03 18:02:37 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_distance(t_node **list, unsigned int next)
{
	t_node			*curr;
	unsigned int	dis;

	curr = *list;
	dis = 0;
	while (curr)
	{
		if (curr->index == next)
			break ;
		dis++;
		curr = curr->next;
	}
	return (dis);
}

unsigned int	get_distance_rev(t_node **list, unsigned int next)
{
	t_node			*curr;
	unsigned int	dis;

	curr = *list;
	dis = 0;
	while (curr)
	{
		if (curr->index == next)
			dis = 0;
		dis++;
		curr = curr->next;
	}
	return (dis);
}

void	print_stacks(t_node **stack_a, t_node **stack_b)
{
	t_node	*curr;

	curr = *stack_a;
	while (curr)
	{
		ft_printf("a - index: %d\t(value: %d)\n", curr->index, curr->value);
		curr = curr->next;
	}
	ft_printf("\n");
	curr = *stack_b;
	while (curr)
	{
		ft_printf("b - index: %d\t(value: %d)\n", curr->index, curr->value);
		curr = curr->next;
	}
}

void	leaks(void)
{
	system("leaks push_swap -q");
}

void	error_exit(int num)
{
	write(1, "Error\n", 7);
	exit(num);
}
