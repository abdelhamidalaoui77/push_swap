/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:50:10 by alamrani          #+#    #+#             */
/*   Updated: 2026/01/08 17:50:23 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
    t_list  *temp;
    int size;

    temp = lst;
    size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return (size);
}
// int main()
// {
// 	t_list	*head = ft_lstnew("Abdelhamid");
//     t_list  *current = ft_lstnew("Lamrani");
//     head->next = current;
    
//     current = ft_lstnew("Alaoui");
//     head->next->next = current;

//     current = ft_lstnew("M9wad");
//     head->next->next->next = current;
    
//     printf("Your linked list size is : %d\n",ft_lstsize(head));
//     t_list *temp;
//     temp = head;
//     while (temp)
//     {
//         printf("Content : %s\n",temp->content);
//         temp = temp->next;
//     }
// }