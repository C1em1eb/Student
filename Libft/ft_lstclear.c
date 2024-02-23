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
