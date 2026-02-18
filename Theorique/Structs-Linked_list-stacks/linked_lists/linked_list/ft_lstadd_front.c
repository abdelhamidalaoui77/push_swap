/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:21:19 by alamrani          #+#    #+#             */
/*   Updated: 2026/01/08 17:22:05 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
    // t_list  *head;

    // head = *lst;
    // new->next= head;
    // *lst = new;
    
    //! Simple approach
    
    new->next = *lst;
    *lst = new;
}

// int main()
// {
// 	t_list	*head = ft_lstnew("Abdelhamid");
//     t_list  *current = ft_lstnew("Lamrani");
//     head->next = current;
    
//     current = ft_lstnew("Alaoui");
//     head->next->next = current;

//     t_list *new = ft_lstnew("M9wad");

//     ft_lstadd_front(&head, new);
//     t_list *temp;
//     temp = head;
//     while (temp)
//     {
//         printf("Content : %s\n",temp->content);
//         temp = temp->next;
//     }
// }