/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:08:33 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/13 09:30:28 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	write_op(char *op)
{
	write(1, op, ft_strlen(op));
}

void	swap(t_stack *stack, char *op)
{
	int	tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->top + 1];
	stack->stack[stack->top + 1] = tmp;
	if (op)
		write_op(op);
}

void	sa(t_stack *stack_a)
{
	swap(stack_a, "sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b, "sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	write_op("ss\n");
}
