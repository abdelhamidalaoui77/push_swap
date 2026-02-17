/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:37:24 by alamrani          #+#    #+#             */
/*   Updated: 2026/02/17 14:58:27 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

int	get_min_position(t_stack *a)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!a)
		return (-1);
	min = a->index;
	min_pos = 0;
	pos = 0;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			min_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (min_pos);
}

void	push_smallest_to_b(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;
	int	rotations;

	size = stack_size(*a);
	pos = get_min_position(*a);
	if (pos <= size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	if (size == 4)
	{
		push_smallest_to_b(a, b);
		sort_three(a);
		pa(a, b);
	}
	else
	{
		push_smallest_to_b(a, b);
		push_smallest_to_b(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
