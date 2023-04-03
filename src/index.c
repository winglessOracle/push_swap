/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 16:32:27 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/04/03 18:01:14 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node **list)
{
	t_node	*curr;
	t_node	*node_min;
	bool	min;

	min = false;
	node_min = NULL;
	curr = *list;
	while (curr)
	{
		if ((curr->index == 0) && (!min || curr->value < node_min->value))
		{
			min = true;
			node_min = curr;
		}	
		curr = curr->next;
	}
	if (min)
		return (node_min);
	else
		return (NULL);
}

unsigned int	ft_index(t_node **list)
{
	t_node			*curr;
	unsigned int	index;

	if (*list == NULL)
		return (0);
	index = 1;
	curr = find_min(list);
	while (curr)
	{
		curr->index = index++;
		curr = find_min(list);
	}
	index--;
	return (index);
}
