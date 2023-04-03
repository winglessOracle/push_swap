/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 18:35:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/24 17:00:48 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <errno.h>
# include <stdbool.h>
# include <limits.h>
//# include <stdio.h>

typedef struct s_node
{
	int				value;
	unsigned int	index;
	struct s_node	*next;
}	t_node;

//checks
int		check_integer(char *number, t_node *stack_a);
int		check_len(char *argv);
int		check_analog(char *number);
int		is_integer(char *str);
int		is_sorted(t_node **list);

//index
t_node			*find_min(t_node **list);
unsigned int	ft_index(t_node **list);

//init_sort
void	sort(t_node **stack_a, t_node **stack_b, unsigned int last_index);
int		init_stack(int argc, char **argv, t_node **stack_a);

//list
t_node	*new_node(int value);
void	insert_back(t_node **list, t_node *new);
t_node	*last_node(t_node *node);
void	free_list(t_node **list);
int		list_size(t_node **list);

//rotate
int		rotate(char ident, t_node **stack_a, t_node **stack_b);
int		rev_rotate(char ident, t_node **stack_a, t_node **stack_b);
int		rotate_up(t_node **list);
int		rotate_down(t_node **list);

//simple
unsigned int	find_highest_3(t_node **list);
void			simple_3(t_node **stack_a, t_node **stack_b);
void			simple_4(t_node **stack_a, t_node **stack_b);
void			simple_5(t_node **stack_a, t_node **stack_b);

//sorting
void	radix_sort(t_node **stack_a, t_node **stack_b, unsigned int last_index);
int		get_next_direction(t_node **list, unsigned int nexts, unsigned int nextb);
int		sortatob(t_node **stack_a, t_node **stack_b, unsigned int nexts, unsigned int last_index);
void	sortbtoa(t_node **stack_a, t_node **stack_b, unsigned int nexts, unsigned int nextb);
void	intersect_sort(t_node **stack_a, t_node **stack_b, unsigned int last_index);

//swap_push
int		swap(char ident, t_node **stack_a, t_node **stack_b);
int		swap_first(t_node **list);
int		push(char ident, t_node **stack_a, t_node **stack_b);
int		push_top(t_node **dst, t_node **src);

//utils
unsigned int	get_distance(t_node **list, unsigned int next);
unsigned int	get_distance_rev(t_node **list, unsigned int next);
void			print_stacks(t_node **stack_a, t_node **stack_b);
void			leaks(void);
void			error_exit(int num);

#endif

/*error handeling:
1:	not enough arguments
2:	error allocating memory in 'set_argv'
3:	error allocating memory for stacks
4:	arguments excede int_max or int_min boundries
5:	double arguments
6:	non integer arguments
7:	error setting value (atoi)
8:	too many arguments
9:	false input
10:	error in node creation
*/
