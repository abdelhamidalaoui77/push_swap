/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:47:37 by alamrani          #+#    #+#             */
/*   Updated: 2026/02/13 18:47:56 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

static int	ft_strslen(int size, char **strs)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest + i);
}

static char	*ft_handle_null_size(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*origin;
	char	*curr;
	int		i;

	if (size == 0)
		return (ft_handle_null_size());
	origin = malloc(ft_strslen(size, strs) + ft_strlen(sep) * (size - 1) + 1);
	if (!origin)
		return (NULL);
	curr = origin;
	i = 0;
	while (i < size)
	{
		curr = ft_strcpy(curr, strs[i]);
		if (i < size - 1)
			curr = ft_strcpy(curr, sep);
		i++;
	}
	*curr = '\0';
	return (origin);
}
