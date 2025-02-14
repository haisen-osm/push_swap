/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:26:42 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:02 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	rra(t_stack *stack_a, int display)
{
	int	temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->stack[stack_a->top + stack_a->size - 1];
	ft_memmove(&stack_a->stack[stack_a->top + 1], &stack_a->stack[stack_a->top],
		(stack_a->size - 1) * sizeof(int));
	stack_a->stack[stack_a->top] = temp;
	if (display)
		write_op("rra\n");
}

void	rrb(t_stack *stack_b, int display)
{
	int	temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->stack[stack_b->top + stack_b->size - 1];
	ft_memmove(&stack_b->stack[stack_b->top + 1], &stack_b->stack[stack_b->top],
		(stack_b->size - 1) * sizeof(int));
	stack_b->stack[stack_b->top] = temp;
	if (display)
		write_op("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int display)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (display)
		write_op("rrr\n");
}
