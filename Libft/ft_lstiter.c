/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:55:59 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/26 19:00:30 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*nodetoapplyfunctionto;

	nodetoapplyfunctionto = lst;
	while (nodetoapplyfunctionto)
	{
		f(nodetoapplyfunctionto->content);
		nodetoapplyfunctionto = nodetoapplyfunctionto->next;
	}
}
