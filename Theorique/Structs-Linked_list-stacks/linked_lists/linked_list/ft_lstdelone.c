/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:59:22 by alamrani          #+#    #+#             */
/*   Updated: 2026/01/08 20:00:09 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
    free(lst);
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

    t_list *current2 = ft_lstnew(ft_strdup("M9wad"));
    head->next->next->next = current2;

    // delete "Alaoui"
    t_list *to_delete = head->next->next;
    head->next->next = to_delete->next;
    ft_lstdelone(to_delete, del);

    t_list *tmp = head;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
}

