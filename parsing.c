/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:44:26 by alamrani          #+#    #+#             */
/*   Updated: 2026/02/14 23:06:14 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_check(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_array_arguements(char **nbrs)
{
	int	i;

	i = 0;
	if (!nbrs)
		return ;
	while (nbrs[i])
		free(nbrs[i++]);
	free(nbrs);
}

int	insert_to_stack_after_parsing(t_stack **stack, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (fill_stack(stack, arr[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	verify_inputs(char **nbrs, int *arr, int *error, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = strict_atoi(nbrs[i], error);
		if (*error)
			return (0);
		i++;
	}
	return (1);
}

int	parse_and_push(t_stack **stack, int ac, char **av)
{
	char	**nbrs;
	int		*arr;
	int		size;
	int		error;

	nbrs = handle_arguments(ac, av);
	if (!nbrs)
		return (-1);
	size = count_array_size(nbrs);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (free_array_arguements(nbrs), -1);
	if (verify_inputs(nbrs, arr, &error, size) == 0)
		return (free(arr), free_array_arguements(nbrs), -1);
	free_array_arguements(nbrs);
	if (duplicate_check(arr, size))
		return (free(arr), -1);
	if (!insert_to_stack_after_parsing(stack, arr, size))
		return (free_stack(stack), free(arr), -1);
	free(arr);
	return (0);
}
