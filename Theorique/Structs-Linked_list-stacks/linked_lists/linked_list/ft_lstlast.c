/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:32:19 by alamrani          #+#    #+#             */
/*   Updated: 2026/01/08 18:34:44 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

// int main()
// {
// 	t_list	*head = ft_lstnew("Abdelhamid");
    
// 	t_list  *current = ft_lstnew("Lamrani");
//     head->next = current;
    
//     current = ft_lstnew("Alaoui");
//     head->next->next = current;

//     current = ft_lstnew("M9wad");
//     head->next->next->next = current;
    
//     printf("Your linked list size is : %d\n",ft_lstsize(head));
// 	t_list *temp = ft_lstlast(head);
//     printf("The address of last node is : %p\n",&temp);
// 	printf("The content : %s\n",temp->content);
// }