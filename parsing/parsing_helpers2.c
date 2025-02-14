/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:11:34 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:14 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

char	**join_arr(char **arr, char **split_arr)
{
	char	**new_arr;

	int (i), (j), (k);
	i = 0;
	j = 0;
	k = -1;
	if (!split_arr)
		return (arr);
	while (arr && arr[i])
		i++;
	while (split_arr[j])
		j++;
	new_arr = malloc((i + j + 1) * sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (++k < i)
		new_arr[k] = arr[k];
	k = -1;
	while (++k < j)
		new_arr[i + k] = split_arr[k];
	new_arr[i + j] = NULL;
	if (arr)
		free(arr);
	return (new_arr);
}

int	get_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	is_number(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		if (av[i][j - 1] == '-' || av[i][j - 1] == '+')
			return (0);
		i++;
	}
	return (1);
}
