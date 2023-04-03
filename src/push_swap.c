/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 11:28:52 by carlo         #+#    #+#                 */
/*   Updated: 2023/04/03 18:01:47 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//atexit(leaks);
int	main(int argc, char **argv)
{
	t_node			**stack_a;
	t_node			**stack_b;
	unsigned int	last_index;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	stack_a = malloc(sizeof(t_node **));
	stack_b = malloc(sizeof(t_node **));
	if (!stack_a || !stack_b)
		error_exit(3);
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(argc, argv, stack_a);
	last_index = ft_index(stack_a);
	if (!(is_sorted(stack_a)))
		sort(stack_a, stack_b, last_index);
	exit(EXIT_SUCCESS);
}
// print_stacks(stack_a, stack_b);