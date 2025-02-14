/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:08:57 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:11 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	is_only_spaces(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			j++;
		i++;
	}
	if (i == j)
		return (0);
	return (1);
}

char	**check_argv(char **av)
{
	char	**split_arr;
	char	**arr;
	int		i;

	i = 1;
	arr = NULL;
	while (av[i])
	{
		if (av[i][0] == '\0')
			exit_error("Error\n", arr, NULL);
		if (!is_only_spaces(av[i]))
			exit_error("Error\n", arr, NULL);
		split_arr = ft_split(av[i], ' ');
		arr = join_arr(arr, split_arr);
		if (split_arr)
			free(split_arr);
		if (!(is_number(arr)))
			exit_error("Error\n", arr, NULL);
		i++;
	}
	return (arr);
}

int	check_dup(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr, char **arr, t_stack *stack)
{
	long (i), (sign), (res);
	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			exit_error("Error\n", arr, stack);
		i++;
	}
	return (sign * res);
}
