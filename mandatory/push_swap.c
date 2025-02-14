/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:57:12 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:21:57 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_b(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (!stack_a)
		return (NULL);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		exit_error("Error\n", NULL, stack_a);
	stack_b->stack = malloc(sizeof(int) * stack_a->size);
	if (!stack_b->stack)
	{
		free(stack_b);
		exit_error("Error\n", NULL, stack_a);
	}
	stack_b->size = 0;
	stack_b->top = stack_a->hold_size;
	stack_b->hold_size = stack_a->hold_size;
	return (stack_b);
}

void	fill_stack(t_stack *stack, char **arr)
{
	int	i;

	i = 0;
	while (i < stack->hold_size)
	{
		stack->stack[i] = ft_atoi(arr[i], arr, stack);
		i++;
	}
	free_arr(arr);
}

t_stack	*fill_a(char **av)
{
	char	**arr;
	int		size;
	t_stack	*stack;

	arr = check_argv(av);
	size = get_size(arr);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->stack = malloc(sizeof(int) * size);
	if (!stack->stack)
	{
		free(stack);
		return (NULL);
	}
	stack->top = 0;
	stack->size = size;
	stack->hold_size = size;
	fill_stack(stack, arr);
	if (check_dup(stack->stack, size) == 0)
		exit_error("Error\n", NULL, stack);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (EXIT_FAILURE);
	a = fill_a(argv);
	if (!a)
		return (EXIT_FAILURE);
	b = initialize_b(a);
	if (!b)
	{
		free_stack(a);
		return (EXIT_FAILURE);
	}
	if (!ft_is_sorted(a))
		sort_stacks(a, b);
	free_stack(a);
	free_stack(b);
	return (EXIT_SUCCESS);
}
