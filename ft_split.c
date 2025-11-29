/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:50:20 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/11/29 15:12:45 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c
			&& (index == 0 || s[index -1] == c))
			count++;
		index++;
	}
	return (count);
}

static char	**free_split(char **result, size_t word_count)
{
	size_t	index;

	index = 0;
	while (index < word_count)
	{
		free(result[index]);
		index++;
	}
	free(result);
	return (NULL);
}

static char	**fill_words(char **result, char const *s, char c, size_t w_count)
{
	size_t	index;
	size_t	word_index;
	size_t	start;

	index = 0;
	word_index = 0;
	while (s[index] != '\0' && word_index < w_count)
	{
		while (s[index] == c)
			index++;
		if (s[index] == '\0')
			break ;
		start = index;
		while (s[index] != '\0' && s[index] != c)
			index++;
		result[word_index] = ft_substr(s, start, index - start);
		if (!result[word_index])
			return (free_split(result, word_index));
		word_index++;
	}
	result[word_index] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_words(result, s, c, word_count));
}
