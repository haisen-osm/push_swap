/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:26:03 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:29:58 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	pb(t_stack *stack_b, t_stack *stack_a, int display)
{
	if (!stack_a || !stack_b || stack_a->size == 0)
		return ;
	stack_b->stack[--stack_b->top] = stack_a->stack[stack_a->top++];
	stack_b->size++;
	stack_a->size--;
	if (display)
		write_op("pb\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b, int display)
{
	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	stack_a->stack[--stack_a->top] = stack_b->stack[stack_b->top++];
	stack_a->size++;
	stack_b->size--;
	if (display)
		write_op("pa\n");
}

void	ra(t_stack *stack_a, int display)
{
	int	temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->stack[stack_a->top];
	ft_memmove(&stack_a->stack[stack_a->top], &stack_a->stack[stack_a->top + 1],
		(stack_a->size - 1) * sizeof(int));
	stack_a->stack[stack_a->top + stack_a->size - 1] = temp;
	if (display)
		write_op("ra\n");
}

void	rb(t_stack *stack_b, int display)
{
	int	temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->stack[stack_b->top];
	ft_memmove(&stack_b->stack[stack_b->top], &stack_b->stack[stack_b->top + 1],
		(stack_b->size - 1) * sizeof(int));
	stack_b->stack[stack_b->top + stack_b->size - 1] = temp;
	if (display)
		write_op("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b, int display)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (display)
		write_op("rr\n");
}
