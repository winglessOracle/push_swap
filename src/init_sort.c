/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 10:53:35 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/04/03 18:04:42 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the last index exceeds INT_MAX and returns if true.
checks last_index to determine which sorting algorithm to use. */
void	sort(t_node **stack_a, t_node **stack_b, unsigned int last_index)
{
	if (last_index == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			swap('a', stack_a, stack_b);
	}
	else if (last_index == 3)
		simple_3(stack_a, stack_b);
	else if (last_index == 4)
		simple_4(stack_a, stack_b);
	else if (last_index == 5)
		simple_5(stack_a, stack_b);
	else if (last_index < 101)
		intersect_sort(stack_a, stack_b, last_index);
	else if (last_index <= 10000) //change to ARG_MAX
		radix_sort(stack_a, stack_b, last_index);
	else
		error_exit(8);
	return ;
}

/* Initializes stack A by iterating over the command line
arguments passed as argv and converts them to integer values
using ft_atoi(). It checks the validity of the integer values
Inserts the node at the end of stack A. 
Returns the index of the last node in the stack, which is
returned to the main function.*/
int	init_stack(int argc, char **argv, t_node **stack_a)
{
	int		i;
	int		j;
	int		value;
	char	**numbers;

	i = 1;
	value = 0;
	numbers = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			error_exit(9);
		numbers = ft_split(argv[i], ' ');
		while (numbers[j])
		{
			check_analog(numbers[j]);
			value = check_integer(numbers[j], *stack_a);
			insert_back(stack_a, new_node(value));
			j++;
		}
		ft_free_array(numbers);
		i++;
	}
	return (0);
}
