# push_swap | CODAM Amsterdam

### Table of Contents

* [Introduction](#introduction)
* [How it Works](#how-it-works)
* [Technical Issues](#technical-issues)
* [Summary](#summary)

## Introduction
This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions.
To succeed we need to use various algorithms and choose the one most suited.

Push_swap program needs to calculate and display on the standard output the smallest sequence of instruction that sorts the integer arguments given in the commandline.
We then have two stacks named a and b.
Stack_a contains the given integers (positive withoutd duplicates) while stack_b is empty.

### Requirements
The goal is to sort stack_a in ascending order numbers into using the following operations:
command  | action |
---|------|
`sa` | swap a - swap the first 2 elements at the top of *stack_a*					|
`sb` | swap b - swap the first 2 elements at the top of *stack_b*	|
`ss` | sa and sb at the same time |
`pa` | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty|
`pb` | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty |
`ra` | rotate a - shift up all elements of *stack_a* by 1. The first element becomes the last one			|
`rb` | rotate b - shift up all elements of *stack_b* by 1. The first element becomes the last one 		|
`rr` | ra and rb at the same time			|
`rra` |  reverse rotate a - shift down all elements of *stack_a* by 1. The last element becomes the first one	|
`rrb` |  reverse rotate b - shift down all elements of *stack_b* by 1. The last element becomes the first one	|
`rrr` | rra and rrb at the same time		|

## How it Works
The main function of the program first checks if there are enough arguments to proceed with the program. If there is only one argument, the function converts it into multiple arguments using set_argv() and set_argc() functions. Then it checks if the command line arguments are valid using check_args() function.

It then allocates memory for two stacks, stack_a and stack_b, initializes them to NULL, and populates stack_a with values from the command line arguments using the init_stack() function. This also indexed the nodes to get rid of padding and negative numbers.

If stack_a is not already sorted, it sorts the stack using the sort() function. If stack_a is still not sorted after sorting, the function returns -1. The program frees memory allocated for stack_a and stack_b using the free_stacks() function before exiting.

The function returns after sorting the stack or determining that it is already sorted.

## Sorting algorithms
Which sorting algorithm to use is determined based on the size of the stack.
- For stack size up to 5 there are standardized algorithms to sort in a mininmum amount of moves.
- up to 100 I use an intersect sort which is only marginally better thatn the radix sort but was a nice exercize.
- over 100 I use radix sort.

March, 2023

For more information visit: [Codam.nl](https://codam.nl/) or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs).