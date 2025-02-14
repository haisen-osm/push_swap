/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:15:53 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:31 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted_arr;

	sorted_arr = sort_array(stack_a);
	if (stack_a->hold_size <= 3)
		sort3(stack_a);
	else if (stack_a->hold_size <= 5)
		sort5(stack_a, stack_b, sorted_arr);
	else
	{
		push_to_b(stack_a, stack_b, sorted_arr);
		push_back(stack_a, stack_b);
	}
	free(sorted_arr);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	int (max), (max_pos);
	if (stack_b->size == 0)
		return ;
	while (stack_b->size > 0)
	{
		get_stack_info(stack_b, &max, &max_pos);
		if (max_pos <= stack_b->size / 2)
		{
			while (stack_b->stack[stack_b->top] != max)
				rb(stack_b, 1);
		}
		else
		{
			while (stack_b->stack[stack_b->top] != max)
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b, int *sortedArr)
{
	int (min), (max), (i), (pos);
	min = 0;
	max = get_max_range(stack_a);
	i = 0;
	while (i < stack_a->hold_size)
	{
		pos = get_position(stack_a->stack[i], sortedArr, stack_a->hold_size);
		if (pos < min)
		{
			push_num_to_b(stack_a->stack[i], stack_a, stack_b);
			min++;
			max++;
			i = stack_a->top;
		}
		else if (pos >= min && pos <= max)
		{
			push_num_to_b2(stack_a->stack[i], stack_a, stack_b);
			min++;
			max++;
			i = stack_a->top;
		}
		else
			i++;
	}
}
