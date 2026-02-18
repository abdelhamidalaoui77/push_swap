/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:22:24 by alamrani          #+#    #+#             */
/*   Updated: 2026/01/08 20:22:44 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

    while (*lst)
    {

        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    }
    free(*lst);
}
void    del(void *data)
{
    free(data);
}

int main(void)
{
    t_list *head = ft_lstnew(ft_strdup("Abdelhamid"));
    t_list *current = ft_lstnew(ft_strdup("Lamrani"));
    head->next = current;

    current = ft_lstnew(ft_strdup("Alaoui"));
    head->next->next = current;

    current = ft_lstnew(ft_strdup("M9wad"));
    head->next->next->next = current;


    ft_lstclear(&head, del);
    if (!head)
    {
        printf("the linked list is freed !!!\n");
    } else
    {
        while (head)
        {
            printf("%s\n", (char *)head->content);
            head = head->next;
        }
    }
}