/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:52:05 by dzuiev            #+#    #+#             */
/*   Updated: 2023/10/30 16:55:44 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, char c);
static size_t	ft_count_words(const char *s, char c);
static char		**ft_split_result(char **result, char const *s, char c, int i);

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	return (ft_split_result(result, s, c, 0));
}

static char	**ft_split_result(char **result, char const *s, char c, int i)
{
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		result[j] = (char *)malloc(sizeof(char) * (ft_wordlen(s + i, c) + 1));
		if (!result[j])
		{
			while (j > 0)
				free(result[--j]);
			free(result);
			return (NULL);
		}
		k = 0;
		while (s[i] && s[i] != c)
			result[j][k++] = s[i++];
		result[j++][k] = '\0';
	}
	result[j] = NULL;
	return (result);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			i += ft_wordlen(&s[i], c);
		}
		else
			i++;
	}
	return (count);
}
