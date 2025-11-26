/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:59:05 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/11/26 20:55:23 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (ptr[index] == ch)
			return ((void *)&ptr[index]);
		index++;
	}
	return (NULL);
}
