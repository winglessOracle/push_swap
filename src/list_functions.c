/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 11:39:00 by carlo         #+#    #+#                 */
/*   Updated: 2023/04/03 18:01:39 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(new_node));
	if (!new_node)
		error_exit(10);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	insert_back(t_node **list, t_node *new)
{
	t_node	*last;

	if (*list == NULL)
		*list = new;
	else
	{
		last = last_node(*list);
		last->next = new;
	}
}

t_node	*last_node(t_node *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}

void	free_list(t_node **list)
{
	t_node	*ptr;
	t_node	*temp;

	ptr = *list;
	while (ptr != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
		temp = NULL;
	}
	free(list);
	list = NULL;
}

int	list_size(t_node **list)
{
	size_t	i;
	t_node	*curr;

	i = 0;
	curr = *list;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
