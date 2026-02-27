/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:34:33 by alamrani          #+#    #+#             */
/*   Updated: 2026/02/14 22:41:49 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	atoi_check_sign(const char *str, int *sign)
{
	*sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			*sign = -1;
			return (1);
		}
		return (1);
	}
	return (0);
}

int	strict_atoi(const char *str, int *error)
{
	long	result;
	int		sign;

	*error = 0;
	result = 0;
	if (atoi_check_sign(str, &sign))
		str++;
	if (*str == '\0')
		return (*error = 1, 0);
	while (*str == '0')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (*error = 1, 0);
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (*error = 1, 0);
		str++;
	}
	return ((int)(result * sign));
}

char	**handle_arguments(int ac, char **av)
{
	char	*str;
	char	**nbrs;

	str = ft_strjoin(ac, av, " ");
	if (!str)
		return (NULL);
	nbrs = ft_split(str, ' ');
	free(str);
	if (!nbrs || !nbrs[0])
	{
		free_array_arguements(nbrs);
		return (NULL);
	}
	return (nbrs);
}

int	count_array_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
