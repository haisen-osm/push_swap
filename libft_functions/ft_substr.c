/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:57:42 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:29:48 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub_str = (char *)malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[len] = '\0';
	return (sub_str);
}
