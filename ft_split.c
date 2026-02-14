/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:46:30 by alamrani          #+#    #+#             */
/*   Updated: 2026/02/13 18:46:35 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	count_words(const char *s, char c)
{
	int	i;
	int	total_words;

	i = 0;
	total_words = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			total_words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (total_words);
}

static	char	*malloc_words(const char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0';
	return (word);
}

static	void	copy_word(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	**fill_words(char **res, const char *s, char c, int words)
{
	int	j;

	j = 0;
	while (j < words)
	{
		while (*s == c)
			s++;
		res[j] = malloc_words(s, c);
		if (!res[j])
		{
			while (j-- > 0)
				free(res[j]);
			free(res);
			return (NULL);
		}
		copy_word(res[j], s, c);
		s += ft_strlen(res[j]);
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (!fill_words(res, s, c, words))
		return (NULL);
	return (res);
}
