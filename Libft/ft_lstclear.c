/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:55:48 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/26 18:55:49 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *nodetoclear;
	while (*lst)
	{
		nodetoclear = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nodetoclear;
	}
	free (*lst)
;	*lst = NULL;
}
