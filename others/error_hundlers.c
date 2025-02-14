/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hundlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:21:44 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:07 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	exit_error(char *err, char **arr, t_stack *stack)
{
	if (err)
		write(2, err, ft_strlen(err));
	if (arr)
		free_arr(arr);
	if (stack)
		free_stack(stack);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	free(stack->stack);
	free(stack);
}
