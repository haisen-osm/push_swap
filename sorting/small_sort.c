/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:28 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:18 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

static void	sort_two(t_stack *stack)
{
	if (stack->stack[stack->top] > stack->stack[stack->top + 1])
		sa(stack);
}

void	sort3(t_stack *stack)
{
	int (a), (b), (c);
	if (stack->size == 2)
	{
		sort_two(stack);
		return ;
	}
	a = stack->stack[stack->top];
	b = stack->stack[stack->top + 1];
	c = stack->stack[stack->top + 2];
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

static void	sort_four(t_stack *stack_a, t_stack *stack_b, int *sorted)
{
	while (stack_a->size > 3)
	{
		if (stack_a->stack[stack_a->top] == sorted[0])
			pb(stack_b, stack_a, 1);
		else
			ra(stack_a, 1);
	}
	sort3(stack_a);
	pa(stack_a, stack_b, 1);
}

void	sort5(t_stack *stack_a, t_stack *stack_b, int *sorted)
{
	if (stack_a->size == 4)
	{
		sort_four(stack_a, stack_b, sorted);
		return ;
	}
	while (stack_a->size > 3)
	{
		if (stack_a->stack[stack_a->top] == sorted[0]
			|| stack_a->stack[stack_a->top] == sorted[1])
			pb(stack_b, stack_a, 1);
		else
			ra(stack_a, 1);
	}
	sort3(stack_a);
	if (stack_b->size == 2 && stack_b->stack[stack_b->top]
		< stack_b->stack[stack_b->top + 1])
		sb(stack_b);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, 1);
}
