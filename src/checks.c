/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 12:25:25 by carlo         #+#    #+#                 */
/*   Updated: 2023/04/03 18:01:21 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the integer 'value' is within the range of a 32-bit
signed integer, and if it is not already present in the stack
Returns 1 if the value is valid and not a duplicate. */
int	check_integer(char *number, t_node *stack_a)
{
	t_node		*curr;
	long int	value;

	curr = stack_a;
	value = ft_atoi_long(number);
	if (value < INT_MIN || value > INT_MAX)
		error_exit(7);
	while (curr)
	{
		if (curr->value == value)
			error_exit(5);
		curr = curr->next;
	}
	return (value);
}

int	check_len(char *argv)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen(argv);
	if (argv[0] == '-' || argv[0] == '+')
		j++;
	while (argv[j] == '0')
		j++;
	if (len - j > 10)
		error_exit(4);
	return (0);
}	

/*checks the validity of the command line arguments.*/
int	check_analog(char *number)
{
	if (is_integer(number) == 0)
		error_exit(6);
	check_len(number);
	return (0);
}

/* Returns 1 if the string is a valid integer and 0 otherwise.
It checks if the first character is a minus sign,
then checks if the remaining characters are digits. */
int	is_integer(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str++;
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

/*checks is the list is sorted inascending order. */
int	is_sorted(t_node **list)
{
	t_node	*curr;

	curr = *list;
	while (curr->next)
	{
		if (curr->index >= curr->next->index)
			return (0);
		curr = curr->next;
	}
	return (1);
}
