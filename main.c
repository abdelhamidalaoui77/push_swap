/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:41:52 by alamrani          #+#    #+#             */
/*   Updated: 2026/02/14 22:31:40 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_values(t_stack	*stack)
{
	while (stack)
	{
		printf(" %d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	handle_sorting(t_stack **a, t_stack **b)
{
	int	size;

	if (size <= 1 || is_sorted(*a))
		return ;
	else if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (parse_and_push(&a, argc - 1, argv + 1) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	handle_sorting(&a, &b);
	free_stack(&a);
	return (0);
}
