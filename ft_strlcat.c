/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:18:38 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/11/26 16:23:05 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	index;

	src_len = ft_strlen(src);
	dest_len = 0;
	while (dest_len < destsize && dest[dest_len] != '\0')
		dest_len++;
	if (dest_len == destsize)
		return (destsize + src_len);
	index = 0;
	while (src[index] && (dest_len + index + 1) < destsize)
	{
		dest[dest_len + index] = src[index];
		index++;
	}
	dest[dest_len + index] = '\0';
	return (dest_len + src_len);
}
