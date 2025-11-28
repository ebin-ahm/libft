/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:26:36 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/11/28 17:24:59 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	index;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (index < len)
	{
		dup[index] = s[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
