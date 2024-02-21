/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:04:04 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/21 18:07:28 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = new;
	node->next = lst;
	return	(node);
}

new->next = *lst;
*lst = new;
