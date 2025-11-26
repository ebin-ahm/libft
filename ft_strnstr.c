/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:27:01 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/11/26 21:43:59 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	index1;
	size_t	index2;

	if (s2[0] == '\0')
		return ((char *)s1);
	index1 = 0;
	while (s1[index1] != '\0' && index1 < len)
	{
		index2 = 0;
		while (s1[index1 + index2] == s2[index2]
			&& s2[index2] != '\0'
			&& (index1 + index2) < len)
		{
			index2++;
		}
		if (s2[index2] == '\0')
			return ((char *)&s1[index1]);
		index1++;
	}
	return (NULL);
}
