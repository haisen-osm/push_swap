/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:13:23 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:23 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	*sort_array(t_stack *stack)
{
	int (*array), (swapped), (i), (tmp);
	array = malloc(stack->size * sizeof(int));
	swapped = 1;
	if (!array)
		return (NULL);
	ft_memmove(array, stack->stack, stack->size * sizeof(int));
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < stack->size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
	return (array);
}

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_position(int nb, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nb == arr[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_max_range(t_stack *stack)
{
	if (stack->hold_size < 100)
		return (11);
	else if (stack->hold_size >= 100 && stack->hold_size < 500)
		return (16);
	else
		return (28);
}

int	find_position(int num, t_stack *stack)
{
	int (i), (pos);
	i = stack->top;
	pos = 0;
	while (i < stack->top + stack->size)
	{
		if (stack->stack[i] == num)
			return (pos);
		i++;
		pos++;
	}
	return (-1);
}
