/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation_example.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:41:50 by alamrani          #+#    #+#             */
/*   Updated: 2026/02/04 20:41:35 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack {
	int	value;
	struct s_stack	*next;
}	t_stack;

void	push(t_stack **a, int value)
{
	t_stack	*node;
	t_stack	*top;

	top = (*a);
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = value;
	node->next = NULL;
	if (!*a)
	{
		*a = node;
		return ;
	}
	while (top->next)
		top = top->next ;
	top->next = node;
}

int	stack_size(t_stack *a)
{
	int	i;

	if (!a)
	{
		write(1, "Invalid input !",15);
		return (0);
	}
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	is_empty(t_stack *a)
{
	int	check;

	check = stack_size(a);
	if (check == 0)
		return (0);
	if (check > 0)
		return (1);
	return (0);
}

void	pop(t_stack **a)
{
	t_stack	*node;
	int	size;
	int	i;

	node = *a;
	size = stack_size(node);
	if (size == 0)
	{
		write(1, "the stack is already empty", 26);
		return ;
	}
	if (size == 1)
	{
		free(node);
		node = NULL;
		*a = node;
		return ;
	}
	else
	{
		i = 0;
		while (i < size - 2)
		{
			node = node->next;
			i++;
		}
		free(node->next);
		node->next = NULL;
	}
	}

int	peek(t_stack *a)
{
	int	last_value;
	
	last_value = 0;
	while (a)
	{
		last_value = a->value;
		a = a->next;
	}
	return (last_value);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	print_values(t_stack *stack)
{
	int	count;

	count = 1;
	while (stack)
	{
		printf("the value : %d\n", stack->value);
		count++;
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		t_stack	*a;
		int	i;
		int	value;
		
		i = 1;
		a = NULL;
		while (av[i])
		{
			value = ft_atoi(av[i]);
			// printf("%d\n", value);
			push(&a, value);
			i++;
		}
		printf("The size of our stack : %d\n.",stack_size(a));
		print_values(a);
		printf("The last value in the stack : %d\n.", peek(a));
		printf("We will pop the last value from stack :\n");
		pop(&a);
		pop(&a);
		printf("new stack values :\n");
		print_values(a);
	}
}
