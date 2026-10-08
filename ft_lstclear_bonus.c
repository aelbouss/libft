/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:39:36 by aelbouss          #+#    #+#             */
/*   Updated: 2024/11/11 23:39:50 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	prev = (*lst);
	while (prev != NULL)
	{
		tmp = prev -> next;
		ft_lstdelone(prev, del);
		prev = tmp;
	}
	(*lst) = NULL;
}
