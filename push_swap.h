/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:25:09 by alamrani          #+#    #+#             */
/*   Updated: 2026/02/16 17:59:30 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* PARSING */
int		parse_and_push(t_stack **stack, int ac, char **av);
int		count_array_size(char **str);
int		strict_atoi(const char *str, int *error);
int		duplicate_check(int *arr, int size);
char	**handle_arguments(int ac, char **av);

/* Parsing helpers */
char	**ft_split(char const *s, char c);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);

/* Handling parsing  Memory Leaks */
void	free_array_arguements(char **nbrs);

/* STACK*/
t_stack	*push_one(int value);
int		fill_stack(t_stack **stack, int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);

/* STACK UTILS */
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	index_stack(t_stack *stack);

/* OPERATIONS */
// swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* SORTING*/
t_stack	*find_min_unindexed(t_stack *stack);
int		get_max_bits(t_stack *a);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b, int size);
void	radix_sort(t_stack **a, t_stack **b);
#endif
