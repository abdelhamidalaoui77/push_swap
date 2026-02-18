/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:57:28 by alamrani          #+#    #+#             */
/*   Updated: 2026/01/08 19:02:22 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	while (head->next)
	{
		head = head->next;
	}
	head->next = new;
}

// int main()
// {
// 	t_list	*head = ft_lstnew("Abdelhamid");
    
// 	t_list  *current = ft_lstnew("Lamrani");
//     head->next = current;
    
//     current = ft_lstnew("Alaoui");
//     head->next->next = current;

//     current = ft_lstnew("M9wad");
	
// 	ft_lstadd_back(&head, current);
// 	t_list *tmp = ft_lstlast(head);
// 	printf("%s\n",tmp->content);
// 	t_list *new = ft_lstnew("frayou");
// 	ft_lstadd_back(&head, new);
// 	t_list *last = ft_lstlast(head);
// 	printf("%s\n",last->content);
// }