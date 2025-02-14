/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:39 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:27 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	rotate_to_num(int num, t_stack *stack_a)
{
	int	pos;

	pos = find_position(num, stack_a);
	if (pos <= stack_a->size / 2)
	{
		while (stack_a->stack[stack_a->top] != num)
			ra(stack_a, 1);
	}
	else
	{
		while (stack_a->stack[stack_a->top] != num)
			rra(stack_a, 1);
	}
}

void	push_num_to_b(int num, t_stack *stack_a, t_stack *stack_b)
{
	rotate_to_num(num, stack_a);
	pb(stack_b, stack_a, 1);
	rb(stack_b, 1);
}

void	push_num_to_b2(int num, t_stack *stack_a, t_stack *stack_b)
{
	rotate_to_num(num, stack_a);
	pb(stack_b, stack_a, 1);
}

void	get_stack_info(t_stack *stack, int *max, int *max_pos)
{
	int	i;
	int	current_pos;

	i = stack->top;
	*max = stack->stack[i];
	*max_pos = 0;
	current_pos = 0;
	while (i < stack->top + stack->size)
	{
		if (stack->stack[i] > *max)
		{
			*max = stack->stack[i];
			*max_pos = current_pos;
		}
		i++;
		current_pos++;
	}
}
