/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:57:34 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:29:38 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup_str;

	if (!str)
		return (0);
	i = 0;
	dup_str = malloc(ft_strlen(str) + 1);
	if (!dup_str)
		return (NULL);
	while (str[i])
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
